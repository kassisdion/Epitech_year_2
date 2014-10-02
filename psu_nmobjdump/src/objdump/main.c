/*
** main.c for main_objdump in /home/faisant/Bureau/projet/PSU_2013_nmobjdump
** 
** Made by florian faisant
** Login   <faisant@epitech.net>
** 
** Started on  Mon Mar 10 16:03:03 2014 florian faisant
** Last update Sun Mar 16 19:03:26 2014 florian faisant
*/

#include	<sys/stat.h>
#include	<fcntl.h>
#include	<stdlib.h>
#include	<sys/mman.h>
#include	<elf.h>
#include	"common/common.h"
#include	"objdump/objdump.h"

static void	*init(char *file, struct stat *s)
{
  int		fd;
  void		*buf;

  fd = xopen(file, O_RDONLY);
  xfstat(fd, s);
  buf = xmmap(NULL, s->st_size, PROT_READ, MAP_PRIVATE, fd, 0);
  return (buf);
}

static bool	run(int argc, char **argv)
{
  Elf64_Ehdr	*elf;
  int		i;
  struct stat	s;

  i = 1;
  while (i < argc)
    {
      elf = init(argv[i], &s);
      if ((unsigned long int)s.st_size < sizeof(Elf64_Ehdr))
	return (ERR("Le taille du header est incorrect"));
      if (!my_objdump(elf, argv[i], s.st_size))
	return (false);
      xmunmap((void *)elf, s.st_size);
      i++;
    }
  return (true);
}

int		main(int argc, char **argv)
{
  if (argc < 2)
    {
      ERR("Mauvais nombre d'argument (%d)", argc - 1);
      return (EXIT_FAILURE);
    }
  else
    run(argc, argv);
  return (EXIT_SUCCESS);
}
