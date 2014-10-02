/*
** section.c for section in /home/faisant/Bureau/projet/PSU_2013_nmobjdump/src/objdump
** 
** Made by florian faisant
** Login   <faisant@epitech.net>
** 
** Started on  Mon Mar 10 18:26:07 2014 florian faisant
** Last update Sun Mar 16 19:28:28 2014 florian faisant
*/

#include		<string.h>
#include		<elf.h>
#include		<stdbool.h>
#include		"objdump/objdump.h"
#include		"common/common.h"

static bool		check_section(char *name)
{
  return (strcmp(name, ".bss") != 0
	  && strcmp(name, ".shstrtab") != 0
	  && strcmp(name, ".symtab") != 0
	  && strcmp(name, ".strtab") != 0
	  && strcmp(name, "") != 0);
}

static bool		get_scn(Elf64_Ehdr *elf, char **strtab,
				size_t size)
{
  Elf64_Shdr		*s;

  s = (void *) elf + elf->e_shoff + (elf->e_shentsize * elf->e_shstrndx);
  if ((void *) s < (void *) elf)
    return (ERR("Adresse de section incorrect"));
  if ((void *) s > ((void *)elf + size))
    return (ERR("Adresse de section incorrect"));
  *strtab =  (void *) elf + s->sh_offset;
  if ((void *)*strtab > ((void *)elf + size))
    return (ERR("Adresse de section incorrect"));
  if ((void *)*strtab < ((void *)elf))
    return (ERR("Adresse de section incorrect"));
  return (true);
}

bool			find_section(Elf64_Ehdr *elf,
				     size_t size)
{
  Elf64_Shdr		*scn;
  char			*strtab;
  int			i;

  if (get_scn(elf, &strtab, size) == false)
    return (false);
  if (!elf->e_shoff)
    return (false);
  i = 0;
  while (i < elf->e_shnum)
    {
      scn = (void *)elf + elf->e_shoff + (elf->e_shentsize * i);
      if ((void *) scn > ((void *)elf + size))
	return (ERR("Adresse de section incorrect"));
      if ((void *) scn < (void *) elf)
	return (ERR("Adresse de section incorrect"));
      if (check_section(strtab + scn->sh_name))
	{	
	  if (print_section(strtab, scn, elf, size) == false)
	    return (false);
	}
      i++;
    }
  return (true);
}
