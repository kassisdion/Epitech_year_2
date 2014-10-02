/*
** common.h for common.h in /home/faisant/Bureau/projet/PSU_2013_nmobjdump
** 
** Made by florian faisant
** Login   <faisant@epitech.net>
** 
** Started on  Mon Mar 10 16:52:39 2014 florian faisant
** Last update Mon Mar 10 18:43:06 2014 florian faisant
*/

#ifndef		COMMON_H_
# define	COMMON_H_

# include	<stdio.h>
# include	<stdbool.h>
# include	<stdlib.h>
# include	<sys/stat.h>

# define	ERR(msg, ...) my_error(__FILE__, __LINE__, msg, ##__VA_ARGS__)

bool		my_error(const char *filename, int line,
			 const char *msg, ...);
int		xopen(char *pathname, int flags);
int		xclose(int fd);
void		*xmmap(void *addr, size_t len, int prot,
		       int flags, int fd, off_t off);
int		xfstat(int fd, struct stat *buf);
int		xmunmap(void *addr, size_t length);

#endif
