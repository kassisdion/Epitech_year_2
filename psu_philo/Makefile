##
## Makefile for nm in /home/olive/progetEpitech/PSU_2013_nmobjdump
## 
## Made by secret_o
## Login   <secret_o@epitech.net>
## 
## Started on  Fri Mar 14 18:43:17 2014 olivier secret
## Last update Thu Mar 20 14:28:09 2014 florian faisant
##

CC		=	gcc
RM		=	@rm -fv
ECHO		=	@echo

NAME		= 	philo

FILE		=	main.c		\
			action.c	\
			init.c		\
			run.c		\
			error.c

SRC		=       $(FILE:%.c=src/%.c)
OBJ		=	$(SRC:src/%.c=obj/%.o)

CFLAGS		=	-W	\
			-Wall	\
			-Wextra	\
			-lpthread

OPTIFLAGS       =       -O3
DEBUGFLAGS      =       -ggdb
LDFLAGS         =       
INCLUDE         =       -I ./include

ifdef TERM

BLACK_COL       =       @tput setaf 0
RED_COL         =       @tput setaf 1
GREEN_COL       =       @tput setaf 2
YELLOW_COL      =       @tput setaf 3
BLUE_COL        =       @tput setaf 4
MAGENTA_COL     =       @tput setaf 5
CYAN_COL        =       @tput setaf 6
WHITE_COL       =       @tput setaf 9

endif

all:		CFLAGS += $(OPTIFLAGS)
all:		$(NAME)

debug:		CFLAGS += $(DEBUGFLAGS) 
debug:		$(NAME)

$(NAME):	obj $(OBJ)
		$(GREEN_COL)
		$(ECHO) $(CC) -o $(NAME) $(CFLAGS) $(INCLUDE) $(LDFLAGS) $(OBJ)
		$(RED_COL)
		@$(CC) -o $(NAME) $(CFLAGS) $(LDFLAGS) $(OBJ)
		$(WHITE_COL)

obj:
		mkdir obj

obj/%.o:        src/%.c Makefile
		$(GREEN_COL)
		$(ECHO) $(CC) -c $<
		$(RED_COL)
		@$(CC) -o $@ $(CFLAGS) $(INCLUDE) -c $<
		$(WHITE_COL)

clean:
		$(RM) -r obj

fclean:		clean
		$(RM) $(NAME)

re:		fclean all 

re_debug:	fclean debug

redebug:	re_debug

.PHONY: 	redebug re_debug re fclean clean debug all
