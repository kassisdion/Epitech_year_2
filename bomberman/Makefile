
ifeq ($(strip $(DEVKITARM)),)
$(error "Please use "make instal" or set DEVKITARM in your environment (export DEVKITARM=<path to>devkitARM)")
endif

# Basic
TARGET = bomberman

CFLAGS += -I include -I .build

# Main
SOURCES_PATH = src
SOURCES = \
  $(SOURCES_PATH)/main.cpp \

# Core
CORE_PATH = $(SOURCES_PATH)/core
SOURCES += \
  $(CORE_PATH)/bomberman.cpp \
  $(CORE_PATH)/controller.cpp \
  $(CORE_PATH)/debug.cpp \
  $(CORE_PATH)/events.cpp \
  $(CORE_PATH)/menu.cpp \
  $(CORE_PATH)/screen.cpp \
  $(CORE_PATH)/screens.cpp \
  $(CORE_PATH)/view.cpp \

# Core / Sound
CORE_SOUND_PATH = $(CORE_PATH)/sound
SOURCES += \
  $(CORE_SOUND_PATH)/music.cpp\


# Graph3d
GRAPH_PATH = $(SOURCES_PATH)/graph3d
SOURCES += \
	$(GRAPH_PATH)/Cube.cpp\
	$(GRAPH_PATH)/PlayerRender.cpp\
	$(GRAPH_PATH)/Texture.cpp\
	$(GRAPH_PATH)/SkyBox.cpp\
	$(GRAPH_PATH)/Cam.cpp\
	$(GRAPH_PATH)/MapRender.cpp\
	$(GRAPH_PATH)/BombRender.cpp\
	$(GRAPH_PATH)/Sprite3D.cpp\



# Core / Views
CORE_VIEWS_PATH = $(CORE_PATH)/views
SOURCES += \
  $(CORE_VIEWS_PATH)/menu.cpp \
  $(CORE_VIEWS_PATH)/EditorView.cpp \
  $(CORE_VIEWS_PATH)/Graph3D.cpp \
  $(CORE_VIEWS_PATH)/miniMap.cpp\

# Core / Game
CORE_GAME_PATH = $(CORE_PATH)/game
SOURCES += \
  $(CORE_GAME_PATH)/bomb.cpp \
  $(CORE_GAME_PATH)/game.cpp \
  $(CORE_GAME_PATH)/ia.cpp \
  $(CORE_GAME_PATH)/map.cpp \
  $(CORE_GAME_PATH)/player.cpp \

# Core / Controllers
CORE_CONTROLLERS_PATH = $(CORE_PATH)/controllers
SOURCES += \
  $(CORE_CONTROLLERS_PATH)/game.cpp \

# Maps
CORE_MAPS_PATH = $(SOURCES_PATH)/maps
SOURCES += \
  $(CORE_MAPS_PATH)/test.cpp \
  $(CORE_MAPS_PATH)/full.cpp \

# Menus
MENU_PATH = $(SOURCES_PATH)/menu
SOURCES += \
  $(MENU_PATH)/help.cpp \
  $(MENU_PATH)/load_game.cpp \
  $(MENU_PATH)/main.cpp \
  $(MENU_PATH)/new_game.cpp \
  $(MENU_PATH)/solo.cpp \
  $(MENU_PATH)/pause.cpp \
  $(MENU_PATH)/win.cpp \
  $(MENU_PATH)/loose.cpp \
  $(MENU_PATH)/nbia.cpp \

# World Type
WORLD_TYPE_PATH = $(SOURCES_PATH)/WorldType

SOURCES += \
  $(WORLD_TYPE_PATH)/WorldType.cpp\
  $(WORLD_TYPE_PATH)/ForestWorld.cpp\
  $(WORLD_TYPE_PATH)/MarioWorld.cpp\
  $(WORLD_TYPE_PATH)/SandWorld.cpp\
  $(WORLD_TYPE_PATH)/SnowWorld.cpp\
  $(WORLD_TYPE_PATH)/UrbanWorld.cpp\

# Minimap
MINIMAP_PATH = $(SOURCES_PATH)/miniMap
#  $(MINIMAP_PATH)/

# Graphics
CORE_GRAPHICS_PATH = $(CORE_PATH)/graphics
SOURCES += \
  $(CORE_GRAPHICS_PATH)/Sprite.cpp \

# Editor Map
EDITOR_MAP_PATH = $(SOURCES_PATH)/EditorMap
SOURCES += \
  $(EDITOR_MAP_PATH)/mapEditor.cpp \
  $(EDITOR_MAP_PATH)/mapEditorSize.cpp \
  $(EDITOR_MAP_PATH)/selectWorld.cpp \

# Utils
UTILS_PATH = $(SOURCES_PATH)/utils
SOURCES += \
  $(UTILS_PATH)/time.cpp \
  $(UTILS_PATH)/encodable.cpp \
  $(UTILS_PATH)/encoder.cpp \

# Utils / Packer
UTILS_PACKER_PATH = $(UTILS_PATH)/packer
SOURCES += \
  $(UTILS_PACKER_PATH)/cpacker.c \
  $(UTILS_PACKER_PATH)/cpacker_get.c \
  $(UTILS_PACKER_PATH)/cpacker_put.c \
  $(UTILS_PACKER_PATH)/cpacker_unpack.c \
  $(UTILS_PACKER_PATH)/cpacker_pack.c \
  $(UTILS_PACKER_PATH)/cpacker_read.c \

# Graphics
GRAPHICS_PATH = graphics
GRAPHICS = \
  $(GRAPHICS_PATH)/menuConnect.png \
  $(GRAPHICS_PATH)/menuMain.png \
  $(GRAPHICS_PATH)/menuSave.png \
  $(GRAPHICS_PATH)/menuSolo.png \
  $(GRAPHICS_PATH)/menuWorld.png \
  $(GRAPHICS_PATH)/splashScreen.png \
  $(GRAPHICS_PATH)/editeurSize.png \
  $(GRAPHICS_PATH)/editeurSplashScreen.png \
  $(GRAPHICS_PATH)/fond.png \
  $(GRAPHICS_PATH)/map.png \
  $(GRAPHICS_PATH)/pause.png \
  $(GRAPHICS_PATH)/empty.png \
  $(GRAPHICS_PATH)/AI.png \
  $(GRAPHICS_PATH)/mariodwall.png \
  $(GRAPHICS_PATH)/marioiwall.png \
  $(GRAPHICS_PATH)/player.png \
  $(GRAPHICS_PATH)/sanddwall.png \
  $(GRAPHICS_PATH)/sandiwall.png \
  $(GRAPHICS_PATH)/snowdwall.png \
  $(GRAPHICS_PATH)/snowiwall.png \
  $(GRAPHICS_PATH)/treeiwall.png \
  $(GRAPHICS_PATH)/treedwall.png \
  $(GRAPHICS_PATH)/urbandwall.png \
  $(GRAPHICS_PATH)/urbaniwall.png \
  $(GRAPHICS_PATH)/bomb.png \
  $(GRAPHICS_PATH)/life.png \
  $(GRAPHICS_PATH)/range.png \
  $(GRAPHICS_PATH)/nbBomb.png \
  $(GRAPHICS_PATH)/editoriwall.png \
  $(GRAPHICS_PATH)/editordwall.png \
  $(GRAPHICS_PATH)/victoire.png \
  $(GRAPHICS_PATH)/defaite.png \
  $(GRAPHICS_PATH)/editeurType.png \
  $(GRAPHICS_PATH)/menuIA.png \

# Audio
AUDIO_PATH = music
AUDIO = \

# Data
DATA_PATH = data
DATA = \
	$(DATA_PATH)/bombeexplose.pcx\
	$(DATA_PATH)/marioewall.pcx\
	$(DATA_PATH)/mariofont.pcx\
	$(DATA_PATH)/sandewall.pcx\
	$(DATA_PATH)/sandfont.pcx\
	$(DATA_PATH)/sandwall.pcx\
	$(DATA_PATH)/snowfloor.pcx\
	$(DATA_PATH)/snowsky.pcx\
	$(DATA_PATH)/treeewall.pcx\
	$(DATA_PATH)/treefont.pcx\
	$(DATA_PATH)/treewall.pcx\
	$(DATA_PATH)/urbanfloor.pcx\
	$(DATA_PATH)/urbansky.pcx\
	$(DATA_PATH)/bombe.pcx\
	$(DATA_PATH)/mariofloor.pcx\
	$(DATA_PATH)/mariowall.pcx\
	$(DATA_PATH)/sandfloor.pcx\
	$(DATA_PATH)/sandsky.pcx\
	$(DATA_PATH)/snowewall.pcx\
	$(DATA_PATH)/snowfont.pcx\
	$(DATA_PATH)/snowwall.pcx\
	$(DATA_PATH)/treefloor.pcx\
	$(DATA_PATH)/treesky.pcx\
	$(DATA_PATH)/urbanewall.pcx\
	$(DATA_PATH)/urbanfont.pcx\
	$(DATA_PATH)/urbanwall.pcx\
	$(DATA_PATH)/bomberman.pcx\
	$(DATA_PATH)/explose.pcx\

# Models
MODELS_PATH = models
MODELS = \
   $(MODELS_PATH)/Bomb.md2 \
   $(MODELS_PATH)/Bomberman.md2 \

MODELS_DATA = $(patsubst $(MODELS_PATH)/%.md2,$(DATA_PATH)/%.bin,$(MODELS))
DATA += $(MODELS_DATA)

# MAKE
include nds.mk

models: $(MODELS_DATA)
.PHONY: models

$(DATA_PATH)/%.bin: $(MODELS_PATH)/%.md2 choo/choo
	choo/choo $< $@

_clean_models:
	@tput setaf 1
	@printf "Cleaning model"
	@rm -f $(MODELS_DATA)
	@tput sgr0

.PHONY clean_models: _clean_models

choo/choo:
	make -C choo

# Doc
doc:
	doxygen Doxyfile
.PHONY: doc

# Run
run: $(OUTPUT_NAME)
	@tput setaf 3
	@printf "Running dsmume...\n"
	@tput sgr0
	@desmume $(OUTPUT_NAME)

instal:
	@printf "Retrieving the script...\n"
	@wget -O script.pl "http://sourceforge.net/p/devkitpro/perlupdaters/ci/master/tree/devkitARMupdate.pl?format=raw"
	@printf "Launching the script...\n"
	@perl "./script.pl"

.PHONY: run
