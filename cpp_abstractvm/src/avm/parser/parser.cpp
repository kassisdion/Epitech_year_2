B1;2802;0c//
// parser.cpp for parser in /home/faisan_f/Bureau/project/cpp_abstractvm
// 
// Made by florian faisant
// Login   <faisan_f@epitech.net>
// 
// Started on  Tue Feb 25 16:56:35 2014 florian faisant
// Last update Thu Apr 24 07:39:31 2014 florian faisant
//

#include <iostream>
#include <istream>
#include <sstream>
#include <deque>
#include <vector>
#include "avm/vm/ivm.hpp"
#include "avm/parser/parser.hpp"
#include "avm/common/exception.hpp"
#include "avm/common/operand_factory.hpp"
#include "avm/common/ioperand.hpp"

avm::parser::Parser::Parser()
{
  this->error_line = 0;
  this->func_tab["push"] = &avm::parser::Parser::push;
  this->func_tab["pop"] = &avm::parser::Parser::pop;
  this->func_tab["dump"] = &avm::parser::Parser::dump;
  this->func_tab["assert"] = &avm::parser::Parser::assert;
  this->func_tab["add"] = &avm::parser::Parser::add;
  this->func_tab["sub"] = &avm::parser::Parser::sub;
  this->func_tab["mul"] = &avm::parser::Parser::mul;
  this->func_tab["div"] = &avm::parser::Parser::div;
  this->func_tab["mod"] = &avm::parser::Parser::mod;
  this->func_tab["print"] = &avm::parser::Parser::print;
  this->func_tab["exit"] = &avm::parser::Parser::exit;
  this->func_tab[";"] = &avm::parser::Parser::comm;
  this->types_tab["int8"] = avm::common::IOperand::Int8;
  this->types_tab["int16"] = avm::common::IOperand::Int16;
  this->types_tab["int32"] = avm::common::IOperand::Int32;
  this->types_tab["float"] = avm::common::IOperand::Float;
  this->types_tab["double"] = avm::common::IOperand::Double;
}

bool avm::parser::Parser::check_line(const std::vector<std::string> &line)
{
  if (this->func_tab.find(line[0]) == this->func_tab.end())
    throw avm::common::AVMSourceException(get_error_line(), "Instruction incorrecte.");
  return ((this->*func_tab[line[0]])(line));
}

static std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems)
{
  std::stringstream ss(s);
  std::string item;
  while (std::getline(ss, item, delim))
    {
      elems.push_back(item);
    }
  return elems;
}

static std::vector<std::string> split(const std::string &s, char delim)
{
  std::vector<std::string> elems;
  split(s, delim, elems);
  return elems;
}

void avm::parser::Parser::parse_file(std::istream &input)
{
  bool brk = true;
  std::string line;
  std::vector<std::string> word_list;

  while (brk)
    {
      if (getline(input, line))
        {
          word_list = split(line, ' ');
          if (word_list.size() > 0)
            brk = check_line(word_list);
          this->error_line++;
        }
      else
        throw avm::common::AVMException("Impossible de trouver l'instruction exit");
    }
}

void avm::parser::Parser::parse_cin(std::istream &input)
{
  bool brk = false;
  std::string line;
  std::deque<std::string> lines;
  std::vector<std::string> word_list;

  while (!brk)
    {
      if (getline(input, line))
	{
	  if (line == ";;")
	    brk = true;
	  else
	    lines.push_back(line);
	}
      else if (input.eof() && !brk)
	throw avm::common::AVMException("L'instruction ;; n'a pas été transmise");
    }

  bool has_exit = false;

  while (!lines.empty())
    {
      std::string line = lines.front();
      lines.pop_front();

      std::vector<std::string> words = split(line, ' ');
      if (!words.empty())
	{
	  if (words[0] == "exit")
	    has_exit = true;
	  brk = check_line(words);
	}
      error_line++;
    }

  if (!has_exit)
    throw avm::common::AVMException("Impossible de trouver l'instruction exit");
}

void avm::parser::Parser::parse(vm::IVM &vm_arg, std::istream &input)
{
  this->vm = &vm_arg;
  if (input == std::cin)
    parse_cin(input);
  else
    parse_file(input);
}

int avm::parser::Parser::get_error_line()
{
  return (error_line);
}

avm::common::IOperand *avm::parser::Parser::get_operand(const std::vector<std::string> &line)
{
  std::vector<std::string> word_list;

  std::string::size_type start = line[1].find('(');
  std::string::size_type end = line[1].find(')');

  if (start == std::string::npos || end == std::string::npos)
    throw avm::common::AVMSourceException(get_error_line(), "Mauvais parenthesage.");

  std::string type_str = line[1].substr(0, start);
  std::string value_str = line[1].substr(start + 1, end - start - 1);

  if (type_str == "" || value_str == "")
    throw avm::common::AVMSourceException(get_error_line(), "Valeur incorrecte.");
  if (types_tab.find(type_str) == types_tab.end())
    throw avm::common::AVMSourceException(get_error_line(), "Type incorrect.");
  avm::common::IOperand::eOperandType type = types_tab[type_str];
  return (avm::common::OperandFactory::createOperand(type, value_str));
}

bool avm::parser::Parser::push(const std::vector<std::string> &line)
{
  if (line.size() == 2)
    {
      avm::common::IOperand *op = get_operand(line);
      if (op)
	vm->push(this, op);
      else
	throw avm::common::AVMSourceException(get_error_line(), "Impossible de recupérer l'operateur");
    }
  else
    throw avm::common::AVMSourceException(get_error_line(), "Nombre d'argument incorrect pour push.");
  return (true);
}

bool avm::parser::Parser::pop(const std::vector<std::string> &line)
{
  if (line.size() == 1)
    vm->pop(this);
  else
    throw avm::common::AVMSourceException(get_error_line(), "Nombre d'argument incorrect pour pop.");
  return (true);
}

bool avm::parser::Parser::dump(const std::vector<std::string> &line)
{
  if (line.size() == 1)
    vm->dump(this);
  else
    throw avm::common::AVMSourceException(get_error_line(), "Nombre d'argument incorrect pour dump.");
  return (true);
}

bool avm::parser::Parser::assert(const std::vector<std::string> &line)
{
  if (line.size() == 2)
    {
      avm::common::IOperand *op = get_operand(line);
      if (op)
	vm->assert(this, op);
      else
	throw avm::common::AVMSourceException(get_error_line(), "Impossible de recupérer l'operateur");
    }
  else
    throw avm::common::AVMSourceException(get_error_line(), "Nombre d'argument incorrect pour assert.");
  return (true);
}

bool avm::parser::Parser::add(const std::vector<std::string> &line)
{
  if (line.size() == 1)
    vm->add(this);
  else
    throw avm::common::AVMSourceException(get_error_line(), "Nombre d'argument incorrect pour add.");
  return (true);
}

bool avm::parser::Parser::sub(const std::vector<std::string> &line)
{
  if (line.size() == 1)
    vm->sub(this);
  else
    throw avm::common::AVMSourceException(get_error_line(), "Nombre d'argument incorrect pour sub.");
  return (true);
}

bool avm::parser::Parser::mul(const std::vector<std::string> &line)
{
  if (line.size() == 1)
    vm->mul(this);
  else
    throw avm::common::AVMSourceException(get_error_line(), "Nombre d'argument incorrect pour mul.");
  return (true);
}

bool avm::parser::Parser::div(const std::vector<std::string> &line)
{
  if (line.size() == 1)
    vm->div(this);
  else
    throw avm::common::AVMSourceException(get_error_line(), "Nombre d'argument incorrect pour div.");
  return (true);
}

bool avm::parser::Parser::mod(const std::vector<std::string> &line)
{
  if (line.size() == 1)
    vm->mod(this);
  else
    throw avm::common::AVMSourceException(get_error_line(), "Nombre d'argument incorrect pour mod.");
  return (true);
}

bool avm::parser::Parser::print(const std::vector<std::string> &line)
{
  if (line.size() == 1)
    vm->print(this);
  else
    throw avm::common::AVMSourceException(get_error_line(), "Nombre d'argument incorrect pour print.");
  return (true);
}

bool avm::parser::Parser::exit(const std::vector<std::string> &line)
{
  if (line.size() == 1)
    vm->exit(this);
  else
    throw avm::common::AVMSourceException(get_error_line(), "Nombre d'argument incorrect pour exit.");
  return (false);
}

bool avm::parser::Parser::comm(const std::vector<std::string> &line)
{
  return (true);
}
