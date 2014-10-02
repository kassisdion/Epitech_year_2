/*
** nm.h for nm.h in /home/faisant/Bureau/projet/PSU_2013_nmobjdump/include
** 
** Made by florian faisant
** Login   <faisant@epitech.net>
** 
** Started on  Mon Mar 10 15:36:49 2014 florian faisant
** Last update Sun Mar 16 18:41:06 2014 florian faisant
*/

#ifndef		NM_H_
# define	NM_H_

# include	<stddef.h>
# include	<stdbool.h>
# include	<elf.h>

bool		my_nm(Elf64_Ehdr *elf, char *file, size_t size);
Elf64_Sym	**get_tab(Elf64_Ehdr *buf, Elf64_Shdr *scn,
			  char *strtab, size_t size);
bool		print(Elf64_Sym **tab, char *strtab);
Elf64_Shdr	*get_symbole(Elf64_Ehdr *buf, char **strtab,
			     size_t size);

#endif
