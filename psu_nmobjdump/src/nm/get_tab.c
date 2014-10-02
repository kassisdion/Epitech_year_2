/*
** symb_tab.c for symb_tab.c in /home/faisant/Bureau/projet/PSU_2013_nmobjdump/src/nm
** 
** Made by florian faisant
** Login   <faisant@epitech.net>
** 
** Started on  Sat Mar 15 22:03:30 2014 florian faisant
** Last update Sun Mar 16 19:40:16 2014 florian faisant
*/

#include		<stdlib.h>
#include		<elf.h>
#include		<string.h>
#include		"common/common.h"

static Elf64_Sym	**sort_tab(Elf64_Sym **tab,
				   char *strtab)
{
  Elf64_Sym		*tmp;
  size_t		i;
  size_t		j;
  size_t		size;

  size = 0;
  while (tab[size])
    size++;
  i = 1;
  while (i < size)
    {
      tmp = tab[i];
      j = i;
      while (j > 0 && strcmp(strtab + tab[j - 1]->st_name,
			     strtab + tmp->st_name) > 0)
	{
	  tab[j] = tab[j - 1];
	  j--;
	}
      tab[j] = tmp;
      i++;
    }
  return (tab);
}

static Elf64_Sym	**make_tab(Elf64_Ehdr *elf,
				   Elf64_Shdr *scn,
				   size_t file_size)
{
  Elf64_Sym		**tab;
  Elf64_Sym		*symtab;
  int			size;
  int			i;

  symtab = (void *)elf + scn->sh_offset;
  if ((void *)symtab < (void *)elf)
    return (NULL);
  if ((void *)symtab > ((void *)elf + file_size))
    return (NULL);
  size = scn->sh_size / scn->sh_entsize;
  tab = malloc(sizeof(**tab) * (size - elf->e_shnum) + 1);
  if (tab == NULL)
    return (NULL);
  i = elf->e_shnum;
  while (i < size)
    {
      tab[i - elf->e_shnum] = symtab + i;
      i++;
    }
  tab[i - elf->e_shnum] = NULL;
  return (tab);
}

Elf64_Sym		**get_tab(Elf64_Ehdr *buf, Elf64_Shdr *scn,
				  char *strtab, size_t size)
{
  Elf64_Sym		**tab;

  tab = make_tab(buf, scn, size);
  if (tab == NULL)
    return (NULL);
  tab = sort_tab(tab, strtab);
  return (tab);
}
