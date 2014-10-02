/*
** xopen.c for xopen in /home/faisant/Bureau/projet/PSU_2013_nmobjdump
** 
** Made by florian faisant
** Login   <faisant@epitech.net>
** 
** Started on  Mon Mar 10 17:29:47 2014 florian faisant
** Last update Mon Mar 10 17:52:56 2014 florian faisant
*/

#include	<stdlib.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	"common/common.h"

int		xopen(char *pathname, int flags)
{
  int		res;

  if ((res = open(pathname, flags)) == -1)
    {
      ERR("Impossible d'ouvrir %s", pathname);
      exit(EXIT_FAILURE);
    }
  return (res);
}
