/*
** utils.c for utils in /home/faisant/Bureau/projet/PSU_2013_nmobjdump
** 
** Made by florian faisant
** Login   <faisant@epitech.net>
** 
** Started on  Mon Mar 10 19:18:58 2014 florian faisant
** Last update Sun Mar 16 19:18:17 2014 florian faisant
*/

#include	<stdbool.h>
#include	<elf.h>
#include	"common/common.h"

static char	*get_class(int cl)
{
  if (cl == ELFCLASS32)
    return ("elf32-x86");
  if (cl == ELFCLASS64)
    return ("elf64-x86-64");
  return ("elf_none");
}

char		*get_other_machine(int ma)
{
  if (ma == EM_PPC)
    return ("PowerPC.");
  else if (ma == EM_PPC64)
    return ("PowerPC 64-bit.");
  else if (ma == EM_S390)
    return ("IBM S/390");
  else if (ma == EM_ARM)
    return ("Advanced RISC Machines");
  else if (ma == EM_SH)
    return ("Renesas SuperH");
  else if (ma == EM_SPARCV9)
    return ("SPARC v9 64-bit.");
  else if (ma == EM_IA_64)
    return ("Intel Itanium");
  else if (ma == EM_X86_64)
    return ("AMD x86-64");
  else if (ma == EM_VAX)
    return ("DEC Vax.");
  return ("Unknow machine");
}

char		*get_machine(int ma)
{
  if (ma == EM_NONE)
    return ("An unknown machine.");
  else if (ma == EM_M32)
    return ("AT&T WE 32100.");
  else if (ma == EM_SPARC)
    return ("Sun Microsystems SPARC.");
  else if (ma == EM_386)
    return ("Intel 80386.");
  else if (ma == EM_68K)
    return ("Motorola 68000.");
  else if (ma == EM_88K)
    return ("Motorola 88000.");
  else if (ma == EM_860) 
    return ("Intel 80860.");
  else if (ma == EM_MIPS)
    return ("MIPS RS3000 (big-endian only).");
  else if (ma == EM_PARISC)
    return ("HP/PA.");
  else if (ma == EM_SPARC32PLUS)
    return ("SPARC with enhanced instruction set.");
  else
    return (get_other_machine(ma));
}

static void	print_flag(int e_type)
{
  if (e_type == ET_NONE)
    printf("FLAG\n");
  else if (e_type == ET_REL)
    printf("REL\n");
  else if (e_type == ET_EXEC)
    printf("EXEC_P\n");
  else if (e_type == ET_DYN)
    printf("DYNAMIC\n");
  else if (e_type == ET_CORE)
    printf("CORE\n");
}

bool		get_carac(Elf64_Ehdr *elf, char *file)
{
  char		*class;
  char		*machine;

  if ((class = get_class(elf->e_ident[EI_CLASS])) == NULL)
    return (ERR("Imposible de trouver la class dans le header"));
  if ((machine = get_machine(elf->e_machine)) == NULL)
    return (ERR("Impossible de trouver la machine dans le header"));
  printf("\n%s:     format de fichier %s\n", file, class);
  printf("architecture: %s, fanions %08x\n", machine, elf->e_flags);
  print_flag(elf->e_type);
  printf("adresse de depart 0x%016x\n\n", (unsigned int)elf->e_entry);
  return (true);
}
