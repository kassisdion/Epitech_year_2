##
## Makefile for Makefile in /home/faisant/Bureau/projet/PSU_2013_nmobjdump
## 
## Made by florian faisant
## Login   <faisant@epitech.net>
## 
## Started on  Mon Mar 10 15:39:45 2014 florian faisant
## Last update Sat Mar 15 22:52:50 2014 florian faisant
##

NAME=		nmobdump
NAME_NM=	my_nm
NAME_OBJDUMP=	my_objdump

RM=		rm -f

CC=		gcc

NM_PATH=	src/nm
COMMON_PATH=	src/common
OBJDUMP_PATH=	src/objdump

SRC_NM=		$(NM_PATH)/main.c		\
		$(NM_PATH)/my_nm.c		\
		$(NM_PATH)/get_symb.c		\
		$(NM_PATH)/get_tab.c		\
		$(NM_PATH)/print.c		\
		$(COMMON_PATH)/error.c		\
		$(COMMON_PATH)/xopen.c		\
		$(COMMON_PATH)/xclose.c		\
		$(COMMON_PATH)/xfstats.c	\
		$(COMMON_PATH)/xmmap.c		\
		$(COMMON_PATH)/xmunmap.c

SRC_OBJDUMP=	$(OBJDUMP_PATH)/main.c		\
		$(OBJDUMP_PATH)/section.c	\
		$(OBJDUMP_PATH)/objdump.c	\
		$(OBJDUMP_PATH)/get_carac.c	\
		$(OBJDUMP_PATH)/print_section.c	\
		$(COMMON_PATH)/error.c          \
		$(COMMON_PATH)/xopen.c          \
		$(COMMON_PATH)/xclose.c         \
		$(COMMON_PATH)/xfstats.c        \
		$(COMMON_PATH)/xmmap.c          \
		$(COMMON_PATH)/xmunmap.c


OBJ_NM=		$(SRC_NM:.c=.o)
OBJ_OBJDUMP=	$(SRC_OBJDUMP:.c=.o)

CFLAGS=		-W		\
		-Wall		\
		-Wextra		\
		-Iinclude

all:			$(NAME)

$(NAME):		$(NAME_NM) $(NAME_OBJDUMP)

$(NAME_NM):		$(OBJ_NM)
			$(CC) -o $(NAME_NM) $(CFLAGS) $(OBJ_NM)

$(NAME_OBJDUMP):	$(OBJ_OBJDUMP)
			$(CC) -o $(NAME_OBJDUMP) $(CFLAGS) $(OBJ_OBJDUMP)

clean:
			$(RM) $(OBJ_COMMON) $(OBJ_NM) $(OBJ_OBJDUMP)

fclean:			clean
			$(RM) $(NAME_NM) $(NAME_OBJDUMP)

re:			fclean all
