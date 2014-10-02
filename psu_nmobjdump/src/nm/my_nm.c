/*
** my_nm.c for my_nm in /home/faisant/Bureau/projet/PSU_2013_nmobjdump/src/nm
** 
** Made by florian faisant
** Login   <faisant@epitech.net>
** 
** Started on  Sat Mar 15 21:39:21 2014 florian faisant
** Last update Sun Mar 16 19:02:00 2014 florian faisant
*/

#include	<stdlib.h>
#include	<stdbool.h>
#include	<elf.h>
#include	"common/common.h"
#include	"nm/nm.h"

bool		my_nm(Elf64_Ehdr *elf, char *file_name, size_t size)
{
  Elf64_Shdr	*sym;
  Elf64_Sym	**tab;
  char		*strtab;

  if (!((elf)->e_ident[EI_MAG0] == ELFMAG0 &&
	(elf)->e_ident[EI_MAG1] == ELFMAG1 &&
	(elf)->e_ident[EI_MAG2] == ELFMAG2 &&
	(elf)->e_ident[EI_MAG3] == ELFMAG3))
    return (ERR("Le fichier %s n'est pas au format elf", file_name));
  if ((elf)->e_ident[EI_CLASS] != ELFCLASS64)
    return (ERR("Format de fichier non supporté"));
  sym = get_symbole(elf, &strtab, size);
  if (sym == NULL)
    return (ERR("Impossible de récupérer la table de symbole"));  
  tab = get_tab(elf, sym, strtab, size);
  if (tab == NULL)
    return (ERR("Impossible de récupérer la sym_tab"));
  print(tab, strtab);
  free(tab);
  return (true);
}
