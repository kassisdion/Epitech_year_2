/*
** xmunmap.c for xmunmap.c in /home/faisant/Bureau/projet/PSU_2013_nmobjdump
** 
** Made by florian faisant
** Login   <faisant@epitech.net>
** 
** Started on  Mon Mar 10 18:38:56 2014 florian faisant
** Last update Mon Mar 10 18:44:40 2014 florian faisant
*/

#include	<stdlib.h>
#include	<sys/mman.h>
#include	"common/common.h"

int		xmunmap(void *addr, size_t length)
{
  int		res;

  if ((res = munmap(addr, length)) == -1)
    {
      ERR("Can't free memory.");
      exit(EXIT_FAILURE);
    }
  return (res);
}
