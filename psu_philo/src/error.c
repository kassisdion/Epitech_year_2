/*
** error.c for error.c in /home/faisan_f/Bureau/project/PSU_2013_myscript/lib
** 
** Made by florian faisant
** Login   <faisan_f@epitech.net>
** 
** Started on  Wed Feb 19 19:55:22 2014 florian faisant
** Last update Sun Mar 23 12:09:52 2014 florian faisant
*/

#include	<stdio.h>
#include	"stdbool.h"

bool		error(char *file, int line, const char *func_name,
		      char *error)
{
  printf("[Error in file : %s, In function : %s, At line : %i] %s\n",
	 file, func_name, line, error);
  return (false);
}
