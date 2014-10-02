/*
** normal.h for PSU_2013_malloc in /home/hervie_g/projects/b3-unix/PSU_2013_malloc
** 
** Made by guillaume hervier
** Login   <hervie_g@epitech.net>
** 
** Started on  Fri Feb  7 20:51:38 2014 guillaume hervier
** Last update Thu Feb 13 17:19:01 2014 guillaume hervier
*/

#ifndef		ALGO_FIRST_FIT_H_
# define	ALGO_FIRST_FIT_H_

# include	<stddef.h>
# include	<stdbool.h>
# include	"my_malloc.h"
# include	"common_fit.h"

void		*first_fit_malloc(t_ctx *ctx, size_t size);
void		*first_fit_realloc(t_ctx *ctx, void *p, size_t size);
void		first_fit_free(t_ctx *ctx, void *p);

bool		first_fit_valid_pointer(t_ctx *ctx, void *p);
t_mblk		*first_fit_find_block(t_ctx *ctx, t_mblk **last, size_t size);
void		first_fit_split_block(t_mblk *block, size_t size);
t_mblk		*first_fit_extend_heap(t_mblk *prev, size_t size);

void		first_fit_show_alloc_mem(t_ctx *ctx);

void		first_fit_init(t_ctx *ctx);

#endif /* ALGO_FIRST_FIT_H_ */
