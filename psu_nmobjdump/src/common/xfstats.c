/*
** xfstats.c for xfstat in /home/faisant/Bureau/projet/PSU_2013_nmobjdump/src/common
** 
** Made by florian faisant
** Login   <faisant@epitech.net>
** 
** Started on  Mon Mar 10 17:42:07 2014 florian faisant
** Last update Mon Mar 10 18:01:48 2014 florian faisant
*/

#include	<stdlib.h>
#include	"common/common.h"

int		xfstat(int fd, struct stat *buf)
{
  int		res;

  if ((res = fstat(fd, buf)) == -1)
    {
      ERR("Can't perform fstat().");
      exit(EXIT_FAILURE);
    }
  return (res);
}
