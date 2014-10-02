/*
** print.c for print.c in /home/faisant/Bureau/projet/PSU_2013_nmobjdump
** 
** Made by florian faisant
** Login   <faisant@epitech.net>
** 
** Started on  Sat Mar 15 22:41:43 2014 florian faisant
** Last update Sun Mar 16 18:46:51 2014 florian faisant
*/

#include	<stdbool.h>
#include	<elf.h>
#include	<stdio.h>

static char	get_carac(int index, int type, int bind)
{
  char		c;

  if (index == SHN_ABS)
    c = 'A';
  else if (type == 0)
    c = 'w';
  else if (index == SHN_UNDEF)
    c = 'U';
  else if (index == 0x2 || index == 0xe)
    c = 'R';
  else if (index == 0x13 || index == 0x14)
    c = 'B';
  else if (index >= 0x7 && index <= 0xb)
    c = 'T';
  else if (index == 0xc || index == 0xd
	   || index == 0x10 || index == 0x11
	   || index == 0x12 || index == 0xf)
    c = 'D';
  else
    c = '?';
  if ((bind == 0) && ((c >= 'A') && (c <= 'Z')))
    c -= ('A' - 'a');
  return (c);
}

static void	get_info_sym(Elf64_Sym *sym)
{
  int		info;
  int		bind;
  int		type;
  int		index;
  char		c;

  info = sym->st_info;
  bind = ELF64_ST_BIND(info);
  type = ELF64_ST_TYPE(info);
  index = sym->st_shndx;
  c = get_carac(index, type, bind);
  printf("%c ", c);
}

bool		print(Elf64_Sym **tab, char *strtab)
{
  int		i;

  i = 0;
  while (tab[i])
    {
      if (ELF64_ST_TYPE(tab[i]->st_info) != STT_FILE)
	{
	  if (tab[i]->st_value)
	    printf("%016x ", (unsigned int)tab[i]->st_value);
	  else
	    printf("\t\t ");
	  get_info_sym(tab[i]);
	  printf("%s\n", strtab + tab[i]->st_name);
	}
      i++;
    }
  return (true);
}
