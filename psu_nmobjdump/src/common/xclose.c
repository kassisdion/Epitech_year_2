/*
** xclose.c for xclose in /home/faisant/Bureau/projet/PSU_2013_nmobjdump/src/common
** 
** Made by florian faisant
** Login   <faisant@epitech.net>
** 
** Started on  Mon Mar 10 17:37:04 2014 florian faisant
** Last update Mon Mar 10 17:52:41 2014 florian faisant
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"common/common.h"

int		xclose(int fd)
{
  int		res;

  if ((res = close(fd)) == -1)
    {
      ERR("Can't perform close()");
      exit(EXIT_FAILURE);
    }
  return (res);
}
