/*
** free.c for PSU_2013_malloc in /mnt/opensuse-home/hervie_g/epitest/projects/b3-unix/PSU_2013_malloc
** 
** Made by guillaume hervier
** Login   <hervie_g@epitech.net>
** 
** Started on  Mon Feb  3 23:16:19 2014 guillaume hervier
** Last update Thu Feb 13 17:00:13 2014 florian faisant
*/

#include	<unistd.h>
#include	"my_malloc.h"
#include	"algo/best_fit.h"

static t_mblk	*best_fit_glue_block(t_mblk *block)
{
  if (block->next && !block->next->allocated)
    {
      block->size += BLOCK_SIZE(block->next->size);
      block->next = block->next->next;
      if (block->next)
	block->next->prev = block;
    }
  return (block);
}

void		best_fit_free(t_ctx *ctx, void *p)
{
  t_mblk	*block;

  if (!best_fit_valid_pointer(ctx, p))
    return;
  block = BLOCK_PTR(p);
  block->allocated = false;
  if (block->prev && !block->prev->allocated)
    block = best_fit_glue_block(block->prev);
  if (block->next)
    block = best_fit_glue_block(block);
  if (!block->next)
    {
      if (block->prev)
	block->prev->next = NULL;
      else
	ctx->root = NULL;
      brk(block);
    }
}
