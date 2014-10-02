##
## Makefile for makefile_cpp_abstract_vm in /home/faisan_f/Bureau/project/cpp_abstractvm
## 
## Made by florian faisant
## Login   <faisan_f@epitech.net>
## 
## Started on  Tue Feb 25 15:24:02 2014 florian faisant
## Last update Tue Feb 25 20:57:40 2014 florian faisant
##

# Paths
CXX			?=	g++

# Flags
CXXFLAGS		=
LDFLAGS			=	$(CXXFLAGS)

# Variables
DEBUG			=	1

ifeq ($(DEBUG),0)
CXXFLAGS		+=	-O3
ifeq ($(CXX),clang++)
CXXFLAGS		+=	-flto
endif
else
CXXFLAGS		+=	-ggdb3
endif

# Rules
all:
clean:
fclean:			clean
re:			fclean all

.PHONY:				\
			all	\
			clean	\
			fclean	\
			re	\

%.o:			%.cpp
	@printf "Compiling %s...\n" "$^"
	@$(CXX) $(CXXFLAGS) -c -o $@ $^

## avm
AVM_SOURCES		=						\
				src/main.cpp				\
				src/avm/common/operand_factory.cpp	\
				src/avm/parser/parser.cpp		\
				src/avm/parser/IParser.cpp		\
				src/avm/common/exception.cpp	\
				src/avm/vm/vm.cpp			\

AVM_OBJECTS		=	$(AVM_SOURCES:.cpp=.o)
AVM_NAME		=	avm

CXXFLAGS		+=	-I include

all:			$(AVM_NAME)

clean_avm:
	rm -f $(AVM_OBJECTS)
.PHONY clean:		clean_avm

fclean_avm:
	rm -f $(AVM_NAME)
.PHONY fclean:		fclean_avm

$(AVM_NAME):		$(AVM_OBJECTS)
	@printf "Linking %s...\n" "$@"
	@$(CXX) $(CXXFLAGS) -o $(AVM_NAME) $(AVM_OBJECTS)
