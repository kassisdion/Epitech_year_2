/*
** macros_malloc.h for PSU_2013_malloc in /home/hervie_g/projects/b3-unix/PSU_2013_malloc
** 
** Made by guillaume hervier
** Login   <hervie_g@epitech.net>
** 
** Started on  Fri Feb  7 21:02:14 2014 guillaume hervier
** Last update Thu Feb 13 17:20:52 2014 guillaume hervier
*/

#ifndef	MACROS_MALLOC_H_
# define MACROS_MALLOC_H_

# include	<stddef.h>
# include	<stdbool.h>
# include	"struct_malloc.h"

# define	MY_MALLOC_MAGIC		0x4233
# define	MY_MALLOC_CONF_PATH	"/etc/malloc.conf"

# define	ALIGN4(x)		(((((x) - 1) >> 2) << 2) + 4)

# define	MAX(a, b)		((a) > (b) ? (a) : (b))
# define	MIN(a, b)		((a) <= (b) ? (a) : (b))

# define	UNUSED			__attribute__((unused))

# define	IS_LOWER(c)		((c) >= 'a' && (c) <= 'z')
# define	IS_UPPER(c)		((c) >= 'A' && (c) <= 'Z')
# define	IS_ALPHA(c)		(IS_LOWER(c) || IS_UPPER(c))

#endif /* MACROS_MALLOC_H_ */
