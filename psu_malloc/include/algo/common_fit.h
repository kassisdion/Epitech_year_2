/*
** common_fit.h for PSU_2013_malloc in /mnt/opensuse-home/hervie_g/epitest/projects/b3-unix/PSU_2013_malloc
** 
** Made by guillaume hervier
** Login   <hervie_g@epitech.net>
** 
** Started on  Thu Feb 13 17:16:34 2014 guillaume hervier
** Last update Thu Feb 13 17:20:45 2014 guillaume hervier
*/

#ifndef		COMMON_FIT_H_
# define	COMMON_FIT_H_

# include	<stddef.h>
# include	<stdbool.h>

# define	DATA_SIZE(size)		((size) - sizeof(t_mblk))
# define	BLOCK_SIZE(size)	((size) + sizeof(t_mblk))

# define	DATA_PTR(block)		((void *)((char *)(block) + sizeof(t_mblk)))
# define	BLOCK_PTR(p)		((t_mblk *)((char *)(p) - sizeof(t_mblk)))

typedef struct	s_mblk	t_mblk;

struct		s_mblk
{
  short		magic;
  t_mblk	*prev;
  t_mblk	*next;
  size_t	size;
  bool		allocated;
};

#endif /* COMMON_FIT_H_ */
