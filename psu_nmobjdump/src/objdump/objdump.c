/*
** utils.c for utils in /home/faisant/Bureau/projet/PSU_2013_nmobjdump
** 
** Made by florian faisant
** Login   <faisant@epitech.net>
** 
** Started on  Mon Mar 10 19:18:58 2014 florian faisant
** Last update Sun Mar 16 19:11:54 2014 florian faisant
*/

#include	<stdbool.h>
#include	<elf.h>
#include	"common/common.h"
#include	"objdump/objdump.h"

bool		my_objdump(Elf64_Ehdr *elf, char *file_name,
			   size_t size)
{
  if (!((elf)->e_ident[EI_MAG0] == ELFMAG0 &&
	(elf)->e_ident[EI_MAG1] == ELFMAG1 &&
	(elf)->e_ident[EI_MAG2] == ELFMAG2 &&
	(elf)->e_ident[EI_MAG3] == ELFMAG3))
    return (ERR("Le fichier %s n'est pas au format elf", file_name));
  if ((elf)->e_ident[EI_CLASS] != ELFCLASS64)
    return (ERR("Format de fichier non supporté"));
  get_carac(elf, file_name);
  if (find_section(elf, size) == false)
    return (ERR("Une section est introuvable"));
  return (true);
}
