/*
** entry.c for PSU_2013_malloc in /mnt/opensuse-home/hervie_g/epitest/projects/b3-unix/PSU_2013_malloc
** 
** Made by guillaume hervier
** Login   <hervie_g@epitech.net>
** 
** Started on  Mon Feb  3 23:16:08 2014 guillaume hervier
** Last update Thu Mar 27 05:27:40 2014 florian faisant
*/

#include	<stddef.h>
#include	<unistd.h>
#include	<string.h>
#include	"my_malloc.h"
#include	"entry_malloc.h"

void		*malloc(size_t size)
{
  void		*p;

  context_acquire();
  if (g_ctx.cfg.print_allocated)
    my_mlog(&g_ctx, INFO, "malloc(%zd)", size);
  p = g_ctx.fn.malloc(&g_ctx, size);
  if (!p)
    my_mlog(&g_ctx, ERROR, "null pointer exception!");
  else if (g_ctx.cfg.init_block)
    memset(p, 0, size);
  if (g_ctx.cfg.print_nb_blocks)
    my_mlog(&g_ctx, INFO, "Blocks: %zd", g_ctx.stat.nb_blocks);
  context_release();
  return (p);
}

void		*calloc(size_t n, size_t size)
{
  void		*p;

  context_acquire();
  if (g_ctx.cfg.print_allocated)
    my_mlog(&g_ctx, INFO, "calloc(%zd, %zd)", n, size);
  context_release();
  p = malloc(n * size);
  context_acquire();
  if (p)
    memset(p, 0, n * size);
  else
    my_mlog(&g_ctx, ERROR, "null pointer exception!");
  if (g_ctx.cfg.print_nb_blocks)
    my_mlog(&g_ctx, INFO, "Blocks: %zd", g_ctx.stat.nb_blocks);
  context_release();
  return (p);
}

void		*realloc(void *p, size_t size)
{
  void		*pp;

  context_acquire();
  if (g_ctx.cfg.print_allocated)
    my_mlog(&g_ctx, INFO, "realloc(%p, %zd)", p, size);
  if (size == 0)
    return (NULL);
  pp = g_ctx.fn.realloc(&g_ctx, p, size);
  if (!pp)
    my_mlog(&g_ctx, ERROR, "null pointer exception!");
  else if (g_ctx.cfg.init_block)
    memset(pp, 0, size);
  if (g_ctx.cfg.print_nb_blocks)
    my_mlog(&g_ctx, INFO, "Blocks: %zd", g_ctx.stat.nb_blocks);
  context_release();
  return (pp);
}

void		free(void *p)
{
  context_acquire();
  if (!p)
    my_mlog(&g_ctx, WARNING, "freeing null pointer.");
  if (g_ctx.cfg.print_unallocated)
    my_mlog(&g_ctx, INFO, "free(%p)", p);
  g_ctx.fn.free(&g_ctx, p);
  if (g_ctx.cfg.print_nb_blocks)
    my_mlog(&g_ctx, INFO, "Blocks: %zd", g_ctx.stat.nb_blocks);
  context_release();
}

void		show_alloc_mem()
{
  context_acquire();
  g_ctx.fn.show_alloc_mem(&g_ctx);
  context_release();
}
