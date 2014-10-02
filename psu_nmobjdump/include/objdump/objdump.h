/*
** objdump.h for objdump.h in /home/faisant/Bureau/projet/PSU_2013_nmobjdump/include
** 
** Made by florian faisant
** Login   <faisant@epitech.net>
** 
** Started on  Mon Mar 10 15:37:30 2014 florian faisant
** Last update Sun Mar 16 19:25:08 2014 florian faisant
*/

#ifndef OBJDUMP_H_
# define OBJDUMP_H_

# include	<elf.h>
# include	<stddef.h>

bool		my_objdump(Elf64_Ehdr *elf, char *file,
			   size_t size);
bool		get_carac(Elf64_Ehdr *elf, char *file);
bool		find_section(Elf64_Ehdr *elf, size_t size);
bool		print_section(char *strtab, Elf64_Shdr *scn,
			      Elf64_Ehdr *elf, size_t size);

#endif
