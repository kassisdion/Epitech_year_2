/*
** error.c for error.c in /home/faisant/Bureau/projet/PSU_2013_nmobjdump/src/common
** 
** Made by florian faisant
** Login   <faisant@epitech.net>
** 
** Started on  Mon Mar 10 16:50:23 2014 florian faisant
** Last update Mon Mar 10 16:52:23 2014 florian faisant
*/

#include	<stdbool.h>
#include	<stdarg.h>
#include	<stdio.h>

bool		my_error(const char *filename, int line,
			 const char *msg, ...)
{
  va_list	ap;

  va_start(ap, msg);
  fprintf(stderr, "[%s:%d] Error: ", filename, line);
  vfprintf(stderr, msg, ap);
  fprintf(stderr, "\n");
  va_end(ap);
  return (false);
}
