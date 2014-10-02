/*
** entry_malloc.h for PSU_2013_malloc in /home/hervie_g/projects/b3-unix/PSU_2013_malloc
** 
** Made by guillaume hervier
** Login   <hervie_g@epitech.net>
** 
** Started on  Fri Feb  7 22:24:02 2014 guillaume hervier
** Last update Sat Feb  8 19:44:22 2014 guillaume hervier
*/

#ifndef		ENTRY_MALLOC_H_
# define	ENTRY_MALLOC_H_

# include	"my_malloc.h"

extern t_ctx	g_ctx;

void		context_acquire();
void		context_release();

#endif /* ENTRY_MALLOC_H_ */
