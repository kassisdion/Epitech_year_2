/*
** init.c for PSU_2013_malloc in /mnt/opensuse-home/hervie_g/epitest/projects/b3-unix/PSU_2013_malloc
** 
** Made by guillaume hervier
** Login   <hervie_g@epitech.net>
** 
** Started on  Fri Feb  7 21:27:39 2014 guillaume hervier
** Last update Thu Feb 13 17:00:37 2014 florian faisant
*/

#include	"algo/best_fit.h"

void		best_fit_init(t_ctx *ctx)
{
  ctx->fn.malloc = best_fit_malloc;
  ctx->fn.realloc = best_fit_realloc;
  ctx->fn.free = best_fit_free;
  ctx->fn.show_alloc_mem = best_fit_show_alloc_mem;
}
