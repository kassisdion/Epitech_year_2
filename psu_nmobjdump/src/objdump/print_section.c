/*
** print_section.c for print_sectio, in /home/faisant/Bureau/projet/PSU_2013_nmobjdump/src/objdump
** 
** Made by florian faisant
** Login   <faisant@epitech.net>
** 
** Started on  Wed Mar 12 21:54:48 2014 florian faisant
** Last update Sun Mar 16 19:27:51 2014 florian faisant
*/

#include	<stdbool.h>
#include	<stdio.h>
#include	<elf.h>
#include	"common/common.h"

static void	print_ascii(Elf64_Shdr *scn, unsigned char *str, int nb)
{
  unsigned int	i;

  i = 0;
  while (i < 16)
    {
      if ((nb + i) < scn->sh_size)
	{
	  if (str[nb + i] >= 32 && str[nb + i] < 127)
	    printf("%c", str[nb + i]);
	  else
	    printf(".");
	}
      else
	printf(" ");
      i++;
    }
}

static void	print_hexa(Elf64_Shdr *scn, unsigned char *str, int nb)
{
  unsigned int	i;

  i = 0;
  while (i < 16)
    {
      if ((nb + i) < scn->sh_size)
	printf("%02x", str[nb + i]);
      else
	printf("  ");
      if ((i % 4) == 3)
	printf(" ");
      i++;
    }
}

static bool	print_scn(Elf64_Shdr *scn, Elf64_Ehdr *elf, size_t size)
{
  unsigned char	*str;
  unsigned int	i;

  str = (void *)elf + scn->sh_offset;
  if ((void *)str < (void *) elf)
    return (ERR("Mauvais adressage"));
  if ((void *)str > ((void *)elf + size))
    return (ERR("Mauvais adressage"));
  i = 0;
  while (i < scn->sh_size)
    {
      printf(" %04x ", (unsigned int)scn->sh_addr + i);
      print_hexa(scn, str, i);
      printf(" ");
      print_ascii(scn, str, i);
      printf("\n");
      i += 16;
    }
  return (true);
}

bool		print_section(char *strtab, Elf64_Shdr *scn,
			      Elf64_Ehdr *elf, size_t size)
{
  printf("Contenu de la section %s:\n", strtab + scn->sh_name);
  if (print_scn(scn, elf, size) == false)
    return (false);
  return (true);
}
