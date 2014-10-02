/*
** get_carac.c for get_carac in /home/faisant/Bureau/projet/PSU_2013_nmobjdump/src/nm
** 
** Made by florian faisant
** Login   <faisant@epitech.net>
** 
** Started on  Sat Mar 15 21:48:12 2014 florian faisant
** Last update Sun Mar 16 18:18:02 2014 florian faisant
*/

#include	<stddef.h>
#include	<stdlib.h>
#include	<elf.h>
#include	"common/common.h"

static void	*scn_get(Elf64_Ehdr *elf, unsigned int type,
			 int pos, size_t size)
{
  Elf64_Shdr	*sct;
  int		i;
  int		fnd;

  fnd = 0;
  i = 0;
  while (i < elf->e_shnum)
    {
      sct = (void *)elf + elf->e_shoff + (elf->e_shentsize * i);
      if ((void *)sct < (void *)elf)
	return (NULL);
      if ((void *) sct > ((void *)elf + size))
	return (NULL);
      if (size < (elf->e_shoff + (i * elf->e_shentsize)))
	return (NULL);
      if (sct->sh_type == type)
	{
	  if (fnd == pos)
	    return (sct);
	  fnd++;
	}
      i++;
    }
  return (NULL);
}

Elf64_Shdr	*get_symbole(Elf64_Ehdr *elf, char **strtab,
			     size_t size)
{
  Elf64_Shdr	*scn;
  Elf64_Shdr	*sym;

  sym = scn_get(elf, SHT_SYMTAB, 0, size);
  if (sym == NULL)
    return (NULL);
  if (!(scn = scn_get(elf, SHT_STRTAB, 2, size)))
    return (NULL);
  *strtab = (void *)elf + scn->sh_offset;
  if ((void *)*strtab > ((void *)elf + size))
    return (NULL);
  if ((void *)*strtab < ((void *)elf))
    return (NULL);
  return (sym);
}
