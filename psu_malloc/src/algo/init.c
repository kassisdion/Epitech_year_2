/*
** init.c for PSU_2013_malloc in /mnt/opensuse-home/hervie_g/epitest/projects/b3-unix/PSU_2013_malloc
** 
** Made by guillaume hervier
** Login   <hervie_g@epitech.net>
** 
** Started on  Fri Feb  7 17:45:33 2014 guillaume hervier
** Last update Thu Feb 13 17:05:37 2014 florian faisant
*/

#include	"my_malloc.h"
#include	"algo/first_fit.h"
#include	"algo/best_fit.h"

void		my_algo_init(t_ctx *ctx)
{
  if (ctx->cfg.algo_type == FIRST_FIT)
    first_fit_init(ctx);
  else if (ctx->cfg.algo_type == BEST_FIT)
    best_fit_init(ctx);
  else
    {
      my_mlog(ctx, INFO, "No algo choice, using default(first_fit).");
      first_fit_init(ctx);
    }
}
