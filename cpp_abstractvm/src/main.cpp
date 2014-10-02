//
// main.cpp for main.cpp in /home/faisan_f/Desktop/project/cpp_abstractvm
// 
// Made by florian faisant
// Login   <faisan_f@epitech.net>
// 
// Started on  Tue Feb 25 21:03:41 2014 florian faisant
// Last update Thu Feb 27 17:29:07 2014 florian faisant
//

#include <cstdlib>
#include <iostream>
#include <fstream>
#include "avm/parser/parser.hpp"
#include "avm/vm/vm.hpp"
#include "avm/common/exception.hpp"

static void start_abstract_vm(std::istream &input)
{
  avm::parser::Parser parser;
  avm::vm::VM vm;

  try
    {
      parser.parse(vm, input);
    }
  catch(const avm::common::AVMException &e)
    {
      std::cerr << "ERROR : " << e.what() << std::endl;
    }
}

static void arg_parse(int argc, char **argv)
{
  std::ifstream file;

  if (argc == 2)
    {
      file.open(argv[1]);
      if (file)
	{
	  start_abstract_vm(file);
	}
      else
	std::cerr << "Impossible d'ouvrir le fichier : " << argv[1] << std::endl;
    }
  else
    {
      std::cerr << "Il a trop d'argument passé en paramétre" << std::endl;
    }
}

int main(int argc, char **argv)
{
  if (argc > 1)
    arg_parse(argc, argv);
  else
    start_abstract_vm(std::cin);
  return (EXIT_SUCCESS);
}
