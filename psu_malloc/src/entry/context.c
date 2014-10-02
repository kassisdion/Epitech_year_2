/*
** entry.c for PSU_2013_malloc in /mnt/opensuse-home/hervie_g/epitest/projects/b3-unix/PSU_2013_malloc
** 
** Made by guillaume hervier
** Login   <hervie_g@epitech.net>
** 
** Started on  Mon Feb  3 23:16:08 2014 guillaume hervier
** Last update Thu Feb 13 16:37:32 2014 florian faisant
*/

#include		<stddef.h>
#include		<unistd.h>
#include		<string.h>
#include		<pthread.h>
#include		"my_malloc.h"
#include		"entry_malloc.h"

static pthread_mutex_t	context_lock = PTHREAD_MUTEX_INITIALIZER;

t_ctx			g_ctx =
  {
    .root			= NULL,
    .cfg =
    {
      .log_level		= NOTHING,
      .abort_error		= false,
      .init_block		= false,
      .abort_on_low_memory	= false,
      .print_allocated		= false,
      .print_unallocated	= false,
      .print_nb_blocks		= false,
      .print_max_nb_blocks	= false,
      .algo_type		= FIRST_FIT,
    },
    .fn =
    {
      .malloc			= NULL,
      .realloc			= NULL,
      .free			= NULL,
    },
    .stat =
    {
      .nb_blocks		= 0,
      .nb_blocks_max		= 0,
    },
  };

static void		my_malloc_init() __attribute__((constructor));
static void		my_malloc_init()
{
  my_conf_init(&g_ctx);
  my_algo_init(&g_ctx);
}

static void		my_malloc_destroy() __attribute__((destructor));
static void		my_malloc_destroy()
{
  if (g_ctx.cfg.print_max_nb_blocks)
    my_mlog(&g_ctx, INFO, "Max blocks: %zd", g_ctx.stat.nb_blocks_max);
}

void			context_acquire()
{
  pthread_mutex_lock(&context_lock);
}

void			context_release()
{
  pthread_mutex_unlock(&context_lock);
}
