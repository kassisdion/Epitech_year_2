/*
** show.c for PSU_2013_malloc in /mnt/opensuse-home/hervie_g/epitest/projects/b3-unix/PSU_2013_malloc
**
** Made by guillaume hervier
** Login   <hervie_g@epitech.net>
**
** Started on  Tue Feb  4 23:34:48 2014 guillaume hervier
** Last update Thu Feb 13 19:21:05 2014 guillaume hervier
*/

#include	<unistd.h>
#include	<stdio.h>
#include	"my_malloc.h"
#include	"algo/best_fit.h"

void		best_fit_show_alloc_mem(t_ctx *ctx)
{
  t_mblk	*block;

  printf("break : %p\n", sbrk(0));
  block = ctx->root;
  while (block)
    {
      if (block->allocated)
	{
	  printf("%p - %p : %zd octets\n",
		 DATA_PTR(block),
		 DATA_PTR(block) + block->size,
		 block->size);
	}
      block = block->next;
    }
}
