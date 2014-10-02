//
// main.cpp for main in /home/faisant/Bureau/projet/cpp_nibbler/source/core
// 
// Made by florian faisant
// Login   <faisant@epitech.net>
// 
// Started on  Mon Mar 24 15:34:49 2014 florian faisant
// Last update Fri Apr  4 11:42:11 2014 florian faisant
//

#include		<stdlib.h>
#include		"common/map.hpp"
#include		"common/event.hpp"
#include		"core/exception.hpp"
#include		"core/nibbler.hpp"

static void		run(char *pwidth, char *pheight, char *path)
{
  int			width;
  int			height;
  std::istringstream	swidth(pwidth);
  std::istringstream	sheight(pheight);

  swidth >> width;
  sheight >> height;
  if (width < 6 || height < 2)
    throw core_exception("La map est trop petite");
  if (width > 55 || height > 30)
    throw core_exception("La map est trop grande");
  Nibbler(width, height, path);
}

int			main(int argc, char **argv)
{
  try
    {
      if (argc != 4)
	throw core_exception("Utilisation : ./nibbler width height lib_XXX.so");
      run(argv[1], argv[2], argv[3]);
    }
  catch (const std::exception &e) 
    { 
      std::cerr << e.what() << "\n"; 
      return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}
