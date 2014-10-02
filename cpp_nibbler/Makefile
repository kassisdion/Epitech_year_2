##
## Makefile for makefile-nibbler in /home/faisant/Bureau/projet/cpp_nibbler
## 
## Made by florian faisant
## Login   <faisant@epitech.net>
## 
## Started on  Thu Apr  3 05:21:46 2014 florian faisant
## Last update Sat Apr  5 18:37:51 2014 aude lejuez
##

#		---NIBBLER---

#flag
CXX			=	g++
RM			=	rm -f
CXXFLAGS		=	-W -Wall -Wextra -fPIC -Iinclude
LIB_FLAGS		=	-ldl
MKDIR			=	@mkdir -p

#common
COMMON_PATH		=	source/common

#utils
UTILS_PATH 		=	source/utils

#core
CORE_NAME		=	nibbler
CORE_PATH		=	source/core
CORE_SOURCE		=	$(CORE_PATH)/main.cpp		\
				$(CORE_PATH)/nibbler.cpp	\
				$(CORE_PATH)/dl_library.cpp	\
				$(CORE_PATH)/exception.cpp	\
				$(CORE_PATH)/snake.cpp		\
				$(CORE_PATH)/fruit.cpp		\
				$(COMMON_PATH)/map.cpp		\
				$(UTILS_PATH)/coord.cpp
CORE_OBJ		=	$(CORE_SOURCE:.cpp=.o)

#		---LIB---
#flag
LIB_CXX_FLAG		=	-shared

#	-SDL
#sdl
LIB_SDL_FLAGS		=	`sdl-config --libs` -lSDL_image -lSDL_ttf
LIB_SDL_NAME		=	lib/lib_nibbler_sdl.so
LIB_SDL_PATH		=	source/lib/sdl
LIB_SDL_SOURCE		=	$(LIB_SDL_PATH)/sdl.cpp
LIB_SDL_OBJ		=	$(LIB_SDL_SOURCE:.cpp=.o)

#	-OPENGL
#opengl
LIB_OPENGL_FLAGS	=	`sdl-config --libs` -lGL -lglut
LIB_OPENGL_NAME		=	lib/lib_nibbler_opengl.so
LIB_OPENGL_PATH		=	source/lib/opengl
LIB_OPENGL_SOURCE	=	$(LIB_OPENGL_PATH)/opengl.cpp
LIB_OPENGL_OBJ		=	$(LIB_OPENGL_SOURCE:.cpp=.o)

#	-NCURSES
#ncurse
LIB_NCURSE_FLAGS	=	-lncurses
LIB_NCURSE_NAME		=	lib/lib_nibbler_ncurses.so
LIB_NCURSE_PATH		=	source/lib/ncurses
LIB_NCURSE_SOURCE	=	$(LIB_NCURSE_PATH)/ncurses.cpp
LIB_NCURSE_OBJ		=	$(LIB_NCURSE_SOURCE:.cpp=.o)

#		----RULES---
all:			$(CORE_NAME)		\
			$(LIB_SDL_NAME)		\
			$(LIB_OPENGL_NAME)	\
			$(LIB_NCURSE_NAME)	

debug:			CXXFLAGS += -ggdb3
debug:			re

clean:			clean_core		\
			clean_lib

fclean:			clean			\
			fclean_core		\
			fclean_lib

re:			fclean all

.PHONY:			all debug clean fclean

#	---NIBBLER
$(CORE_NAME):		$(CORE_OBJ)
			$(CXX) $(CXXFLAGS) -o $(CORE_NAME) $(CORE_OBJ) $(LIB_FLAGS)

clean_core:
			$(RM) $(CORE_OBJ)

fclean_core:	
			$(RM) $(CORE_NAME)

.PHONY:			clean_core fclean_core

#	---LIB
clean_lib:		clean_lib_sdl		\
			clean_lib_opengl

fclean_lib:		fclean_lib_sdl		\
			fclean_lib_opengl

#SDL
$(LIB_SDL_NAME):	$(LIB_SDL_OBJ) 
			$(MKDIR) lib/
			$(CXX) $(CXXFLAGS) $(LIB_CXX_FLAG) -o $(LIB_SDL_NAME) $(LIB_SDL_OBJ) $(LIB_SDL_FLAGS)

clean_lib_sdl:
			$(RM) $(LIB_SDL_OBJ)

fclean_lib_sdl:		clean_lib_sdl
			$(RM) $(LIB_SDL_NAME)

.PHONY:			clean_lib_sdl fclean_lib_sdl

#OPENGL
$(LIB_OPENGL_NAME):	$(LIB_OPENGL_OBJ)
			$(CXX) $(CXXFLAGS) $(LIB_CXX_FLAG) -o $(LIB_OPENGL_NAME) $(LIB_OPENGL_OBJ) $(LIB_OPENGL_FLAGS)

clean_lib_opengl:
			$(RM) $(LIB_OPENGL_OBJ)

fclean_lib_opengl:	clean_lib_opengl
			$(MKDIR) lib/
			$(RM) $(LIB_OPENGL_NAME)

.PHONY:			clean_lib_opengl fclean_lib_opengl

#NCURSE
$(LIB_NCURSE_NAME):	$(LIB_NCURSE_OBJ)
			$(CXX) $(CXXFLAGS) $(LIB_CXX_FLAG) -o $(LIB_NCURSE_NAME) $(LIB_NCURSE_OBJ) $(LIB_NCURSE_FLAGS)
clean_lib_ncurse:
			$(RM) $(LIB_NCURSE_OBJ)

fclean_lib_ncurse:	clean_lib_ncurse
			$(MKDIR) lib/
			$(RM) $(LIB_NCURSE_NAME)

.PHONY:			clean_lib_ncurse fclean_lib_ncurse

