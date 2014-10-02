# Paths
TOOLS_PATH            := $(DEVKITARM)/bin
TOOLS_PREFIX          := $(TOOLS_PATH)/arm-none-eabi-

ifndef USE_CLANG
NDS_CC                := $(TOOLS_PREFIX)gcc
NDS_CXX               := $(TOOLS_PREFIX)g++
NDS_AS                := $(TOOLS_PREFIX)as
else
NDS_CC                := clang
NDS_CXX               := clang++
endif

GRIT                  := $(TOOLS_PATH)/grit
NDSTOOL               := $(TOOLS_PATH)/ndstool
MMUTIL                := $(TOOLS_PATH)/mmutil
BIN2S                 := $(TOOLS_PATH)/bin2s
PYTHON                ?= python2

# Flags
NDS_CFLAGS            += $(CFLAGS)

ifndef USE_CLANG
ARCH                  := -mthumb -mthumb-interwork

NDS_CFLAGS            += -march=armv5te -mtune=arm946e-s -fomit-frame-pointer
NDS_CFLAGS            += -ffast-math

ASFLAGS               += $(ARCH)
else
NDS_CFLAGS            += -march=armv5te
endif

NDS_CFLAGS            += -DARM9

NDS_CCFLAGS           += $(NDS_CFLAGS)
NDS_CXXFLAGS          += $(NDS_CFLAGS)
NDS_CXXFLAGS          += -fno-rtti -fno-exceptions
NDS_CXXFLAGS          += -std=c++11

LDFLAGS               += $(NDS_CFLAGS)
LDFLAGS               += -specs=ds_arm9.specs
LIBS                  +=

# Variables
BUILDDIR              ?= .build
DEBUG                 ?= 1

OBJECT                =  $(BUILDDIR)/$(1).o
DEP                   =  $(BUILDDIR)/$(1).deps.mk

OBJECTS               =  $(foreach src,$(1),$(call OBJECT,$(src)))
DEPS                  =  $(foreach src,$(1),$(call DEP,$(src)))

LIBDIRS               =  $(DEVKITPRO)/libnds
LIBNAMES              =  fat nds9 mm9

NDS_CFLAGS            += -I $(BUILDDIR)
NDS_CFLAGS            += $(foreach dir,$(LIBDIRS),-I $(dir)/include)

LIBS                  += $(foreach dir,$(LIBDIRS),-L $(dir)/lib)
LIBS                  += $(foreach lib,$(LIBNAMES),-l$(lib))

ifeq ($(DEBUG),1)
NDS_CFLAGS            += -ggdb3
else
NDS_CFLAGS            += -O3 	\
			-msse	\
			-msse2	\
			-msse3	\
			-mmmx	\
			-m3dnow
ifdef USE_CLANG
NDS_CFLAGS            += -flto
endif
endif

# Rules
all:
clean:
fclean:               clean
re:                   fclean all

.SUFFIXES:
.SECONDARY:

# Main rules
OUTPUT_NAME           = $(TARGET).nds
OUTPUT_ELF_NAME       = $(BUILDDIR)/$(TARGET).elf

GRAPHICS_SOURCES      = $(foreach path,$(GRAPHICS),$(BUILDDIR)/$(path).c)
GRAPHICS_OBJECTS      = $(foreach src,$(GRAPHICS_SOURCES),$(src).o)
GRAPHICS_DEPS         = $(foreach src,$(GRAPHICS_SOURCES),$(src).deps.mk)

DATA_SOURCES          = $(foreach path,$(DATA),$(BUILDDIR)/$(path).c)
DATA_OBJECTS          = $(foreach src,$(DATA_SOURCES),$(src).o)
DATA_DEPS             = $(foreach src,$(DATA_SOURCES),$(src).deps.mk)

ifneq ($(AUDIO),)
DATA_SOURCES          += $(BUILDDIR)/soundbank.bin.c
endif

OUTPUT_OBJECTS        = \
  $(GRAPHICS_OBJECTS) \
  $(DATA_OBJECTS) \
  $(call OBJECTS,$(SOURCES)) \

OUTPUT_DEPS           = \
  $(GRAPHICS_DEPS) \
  $(DATA_DEPS) \
  $(call DEPS,$(SOURCES)) \

ifeq ($(strip $(filter %.cpp,$(SOURCES))),)
OUTPUT_LD             = $(NDS_CC)
else
OUTPUT_LD             = $(NDS_CXX)
endif

all:                  $(OUTPUT_NAME)

debug:
	@echo $(OUTPUT_OBJECTS)

_target_clean:
	@tput setaf 1
	@printf "Cleaning object\n"
	@rm -f $(OUTPUT_OBJECTS)
	@tput sgr0
.PHONY clean:         _target_clean

_target_fclean:
	@tput setaf 1
	@printf "Cleaning executable\n"
	@rm -f $(OUTPUT_NAME) $(OUTPUT_ELF_NAME)
	@tput sgr0
.PHONY fclean:        _target_fclean

$(OUTPUT_ELF_NAME):   $(OUTPUT_OBJECTS)
	@tput setaf 1
	@printf "Linking: $@\n"
	@tput sgr0
ifndef USE_CLANG
	@$(OUTPUT_LD) $(LDFLAGS) -o $(OUTPUT_ELF_NAME) $(OUTPUT_OBJECTS) $(LIBS)
else
	@$(OUTPUT_LD) $(LDFLAGS) -o $(OUTPUT_ELF_NAME) $(OUTPUT_OBJECTS) $(LIBS)
endif

$(OUTPUT_NAME):       $(OUTPUT_ELF_NAME)
	@tput setaf 1
	@printf "Generating: $@\n"
	@tput sgr0
	@$(NDSTOOL) $(NDSTOOLFLAGS) -c $@ -9 $< >/dev/null
-include $(OUTPUT_DEPS)

# Common rules
_build_fclean:
	@tput setaf 1
	@printf "Cleaning .build repository\n"
	@tput sgr0
	@rm -rf $(BUILDDIR)
.PHONY fclean:        _build_fclean

$(BUILDDIR)/%.cpp.o:  %.cpp
	@tput setaf 2
	@printf "Compiling: $<\n"
	@tput sgr0
	@mkdir -p $(dir $@)
	@$(NDS_CXX) $(NDS_CXXFLAGS) -MD -MF $(call DEP,$<) -c -o $@ $<

$(BUILDDIR)/%.c.o:    %.c
	@tput setaf 2
	@printf "Compiling: $<\n"
	@tput sgr0
	@mkdir -p $(dir $@)
	@$(NDS_CC) $(NDS_CCFLAGS) -MD -MF $(call DEP,$<) -c -o $@ $<

%.cpp.o:              %.cpp
	@mkdir -p $(dir $@)
	@tput setaf 3
	$(NDS_CXX) $(NDS_CXXFLAGS) -MD -MF $@.deps.mk -c -o $@ $<
	@tput sgr0

%.c.o:                %.c
	@tput setaf 3
	@printf "Compiling: $<\n"
	@tput sgr0
	@mkdir -p $(dir $@)
	@$(NDS_CC) $(NDS_CCFLAGS) -MD -MF $@.deps.mk -c -o $@ $<

%.S.o:                %.S
	@tput setaf 3
	@printf "Compiling: $<\n"
	@tput sgr0
	@mkdir -p $(dir $@)
	@$(NDS_AS) -o $@ $<

## Data rules
# define DATA_RULES
# $$(BUILDDIR)/$(1).S:  $(1)
# 	@mkdir -p $$(dir $$@)
# 	$(PYTHON) tools/bin2c.py $(1) $$(dir $$(BUILDDIR)/$(1).c)
# 	$(BIN2S) $(1) > $$@
# $$(BUILDDIR)/$$(basename $(1)).h: $$(BUILDDIR)/$(1).S
# endef
define DATA_RULES
$$(BUILDDIR)/$(1).c:  $(1)
	@tput setaf 6
	@printf "Generating: $$(notdir $$@)\n"
	@tput sgr0
	@mkdir -p $$(dir $$@)
	@$$(PYTHON) tools/bin2c.py $(1) $$(dir $$(BUILDDIR)/$(1).c)
$$(BUILDDIR)/$$(basename $(1)).h: $$(BUILDDIR)/$(1).c
endef

$(foreach data,$(DATA),$(eval $(call DATA_RULES,$(data))))

## Images rules
define IMAGE_RULES
$$(BUILDDIR)/$(1).c:  $(1)
	@tput setaf 6
	@printf "Generating: $$(notdir $$@)\n"
	@tput sgr0
	@mkdir -p $$(dir $$@)
	@$$(GRIT) $$< -ftc -o $$(BUILDDIR)/$$(basename $(1))
	@mv $$(BUILDDIR)/$$(basename $(1)).c $$@
$$(BUILDDIR)/$$(basename $(1)).h:  $$(BUILDDIR)/$(1).c
endef

$(foreach graphic,$(GRAPHICS),$(eval $(call IMAGE_RULES,$(graphic))))

## Audio rule
$(BUILDDIR)/soundbank.bin: $(AUDIO)
	@tput setaf 6
	@printf "Generating: $(notdir $@)\n"
	@tput sgr0
	@mkdir -p $(dir $@)
	@$(MMUTIL) -d -o$(BUILDDIR)/soundbank.bin -h$(BUILDDIR)/soundbank.bin.h $(AUDIO)

$(BUILDDIR)/soundbank.bin.c: $(BUILDDIR)/soundbank.bin
	@tput setaf 6
	@printf "Generating: $(notdir $@)\n"
	@tput sgr0
	@mkdir -p $(dir $@)
	@$(PYTHON) tools/bin2c.py -I "soundbank.bin.h" $(BUILDDIR)/soundbank.bin $(BUILDDIR)
$(BUILDDIR)/soundbank.h:     $(BUILDDIR)/soundbank.bin.c
