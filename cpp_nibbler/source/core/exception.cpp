//
// exception.cpp for exception.cpp in /home/faisant/Bureau/projet/cpp_nibbler
// 
// Made by florian faisant
// Login   <faisant@epitech.net>
// 
// Started on  Mon Mar 24 19:42:00 2014 florian faisant
// Last update Tue Apr  1 18:34:37 2014 florian faisant
//

#include	"core/exception.hpp"

core_exception::core_exception(const std::string &msg)
{
  std::ostringstream oss; 
  oss << "Erreur : " << msg;
  this->msg = oss.str();
}

core_exception::~core_exception() throw() 
{
}

const char	*core_exception::what() const throw()
{
  return this->msg.c_str();
}

