/*
** xmmap.c for xmmap in /home/faisant/Bureau/projet/PSU_2013_nmobjdump/src/common
** 
** Made by florian faisant
** Login   <faisant@epitech.net>
** 
** Started on  Mon Mar 10 17:55:17 2014 florian faisant
** Last update Mon Mar 10 19:07:01 2014 florian faisant
*/

#include	<stdlib.h>
#include	<sys/mman.h>
#include	"common/common.h"

void		*xmmap(void *addr, size_t len, int prot,
		       int flags, int fd, off_t off)
{
  void		*res;

  res = mmap(addr, len, prot, flags, fd, off);
  if (res == MAP_FAILED)
    {
      ERR("Can't alloc memory.");
      exit(EXIT_FAILURE);
    }
  return (res);
}
