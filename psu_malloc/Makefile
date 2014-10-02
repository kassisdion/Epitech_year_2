##
## Makefile for PSU_2013_malloc in /mnt/opensuse-home/hervie_g/epitest/projects/b3-unix/PSU_2013_malloc
## 
## Made by guillaume hervier
## Login   <hervie_g@epitech.net>
## 
## Started on  Mon Feb  3 23:17:27 2014 guillaume hervier
## Last update Tue Jul 22 09:33:38 2014 florian faisant
##

# Env variables
HOSTTYPE		?=	$(shell uname -m)
DEBUG			?=	0

# Programs variables
CC			?=	gcc

# Compile/Link flags
FLAGS			:=	-Wall -Wextra -fPIC -std=gnu89 -D_REENTRANT
ifeq ($(DEBUG),1)
FLAGS			+=	-ggdb3 -DDEBUG=1
else
FLAGS			+=	-O3
ifeq ($(CC),clang)
FLAGS			+=	-flto
endif
endif

CFLAGS			:=	$(FLAGS) -I include
LDFLAGS			:=	$(FLAGS) -shared
LIBS			:=	-lpthread

# Sources

SRC_COMMON		=	src/entry/api.c			\
				src/entry/context.c		\
				src/log.c			\
				src/conf/init.c			\
				src/algo/init.c			\


SRC_FIRST_FIT		=	src/algo/first_fit/malloc.c	\
				src/algo/first_fit/realloc.c	\
				src/algo/first_fit/free.c	\
				src/algo/first_fit/utils.c	\
				src/algo/first_fit/show.c	\
				src/algo/first_fit/init.c	\

SRC_BEST_FIT		=	src/algo/best_fit/malloc.c	\
				src/algo/best_fit/realloc.c	\
				src/algo/best_fit/free.c	\
				src/algo/best_fit/utils.c	\
				src/algo/best_fit/show.c	\
				src/algo/best_fit/init.c	\


SRCS			=	$(SRC_COMMON)			\
				$(SRC_FIRST_FIT)		\
				$(SRC_BEST_FIT)			\

INCS			:=	include/my_malloc.h		\
				include/struct_malloc.h		\

OBJS			:=	$(SRCS:.c=.o)

# Targets
LIBNAME			:=	my_malloc
LIBNAME_ARCH		:=	$(LIBNAME)_$(HOSTTYPE)

LIBFILENAME		:=	lib$(LIBNAME).so
LIBFILENAME_ARCH	:=	lib$(LIBNAME_ARCH)-linux.so

# Rules
all:			$(LIBNAME)
.PHONY:			all

$(LIBNAME):		$(LIBFILENAME_ARCH) $(LIBFILENAME)
.PHONY:			$(LIBNAME)

$(LIBFILENAME):
			ln -s $(LIBFILENAME_ARCH) $(LIBFILENAME)

$(LIBFILENAME_ARCH):	$(OBJS)
			$(CC) $(LDFLAGS) -o $(LIBFILENAME_ARCH) $(OBJS) $(LIBS)

%.o:			%.c
			$(CC) $(CFLAGS) -c -o $@ $<

$(OBJS):		$(INCS)

clean:
			find -type f -name '*~' -delete
			rm -f $(OBJS)
.PHONY:			clean

fclean:			clean
			rm -f $(LIBFILENAME_ARCH) $(LIBFILENAME)
.PHONY:			fclean

re:			fclean all
.PHONY:			re
