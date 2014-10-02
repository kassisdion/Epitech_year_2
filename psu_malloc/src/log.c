/*
** log.c for PSU_2013_malloc in /mnt/opensuse-home/hervie_g/epitest/projects/b3-unix/PSU_2013_malloc
** 
** Made by guillaume hervier
** Login   <hervie_g@epitech.net>
** 
** Started on  Fri Feb  7 18:33:43 2014 guillaume hervier
** Last update Mon Feb 10 17:27:40 2014 guillaume hervier
*/

#include	<stdarg.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	"my_malloc.h"

void		my_mlog(t_ctx *ctx, t_log_level level,
			const char *msg, ...)
{
  va_list	ap;
  FILE		*logfile;

  if (level < ctx->cfg.log_level)
    return;
  logfile = stdout;
  va_start(ap, msg);
  fprintf(logfile, "[malloc] ");
  vfprintf(logfile, msg, ap);
  fprintf(logfile, "\n");
  fflush(logfile);
  va_end(ap);
  if (level >= WARNING && ctx->cfg.abort_error)
    abort();
}
