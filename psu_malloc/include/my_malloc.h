/*
** my_malloc.h for PSU_2013_malloc in /mnt/opensuse-home/hervie_g/epitest/projects/b3-unix/PSU_2013_malloc
** 
** Made by guillaume hervier
** Login   <hervie_g@epitech.net>
** 
** Started on  Mon Feb  3 23:17:17 2014 guillaume hervier
** Last update Fri Feb  7 21:13:49 2014 guillaume hervier
*/

#ifndef	MY_MALLOC_H_
# define MY_MALLOC_H_

# include	<stddef.h>
# include	<stdbool.h>
# include	"struct_malloc.h"
# include	"macros_malloc.h"

/*
** conf/
*/
void		my_conf_init(t_ctx *ctx);

/*
** algo/
*/
void		my_algo_init(t_ctx *ctx);

/*
** log.c
*/
void		my_mlog(t_ctx *ctx, t_log_level level,
			const char *msg, ...);

#endif /* MY_MALLOC_H_ */
