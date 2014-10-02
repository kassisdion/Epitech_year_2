/*
** realloc.c for PSU_2013_malloc in /mnt/opensuse-home/hervie_g/epitest/projects/b3-unix/PSU_2013_malloc
** 
** Made by guillaume hervier
** Login   <hervie_g@epitech.net>
** 
** Started on  Mon Feb  3 23:16:43 2014 guillaume hervier
** Last update Thu Feb 13 17:01:13 2014 florian faisant
*/

#include	<stddef.h>
#include	<string.h>
#include	"my_malloc.h"
#include	"algo/best_fit.h"

static bool	check_extend_block(UNUSED t_ctx *ctx, t_mblk *block, size_t size)
{
  if (block->next && !block->next->allocated)
    return (block->size + BLOCK_SIZE(block->next->size) >= size);
  return (false);
}

static void	*extend_block(UNUSED t_ctx *ctx, t_mblk *block, size_t size)
{
  block->size += BLOCK_SIZE(block->next->size);
  if (block->next->next)
    block->next->next->prev = block;
  block->next = block->next->next;
  if ((block->size - size) >= sizeof(t_mblk))
    best_fit_split_block(block, size);
  return (DATA_PTR(block));
}

void		*best_fit_realloc(t_ctx *ctx, void *p, size_t size)
{
  t_mblk	*block;
  void		*np;

  if (!p)
    return (ctx->fn.malloc(ctx, size));
  if (!best_fit_valid_pointer(ctx, p))
    return (NULL);
  size = ALIGN4(size);
  block = BLOCK_PTR(p);
  if (check_extend_block(ctx, block, size))
    return (extend_block(ctx, block, size));
  np = ctx->fn.malloc(ctx, size);
  memcpy(np, p, MIN(block->size, size));
  ctx->fn.free(ctx, p);
  return (np);
}
