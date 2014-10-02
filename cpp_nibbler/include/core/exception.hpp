//
// exeption.hpp for exeption in /home/faisant/Bureau/projet/cpp_nibbler
// 
// Made by florian faisant
// Login   <faisant@epitech.net>
// 
// Started on  Mon Mar 24 19:20:49 2014 florian faisant
// Last update Tue Apr  1 18:16:22 2014 florian faisant
//

#ifndef		CORE_EXEPTION_HPP
# define	CORE_EXEPTION_HPP

#include	<iostream> 
#include	<sstream> 
#include	<exception> 
  
class		core_exception : public std::exception 
{ 
public:
  core_exception(const std::string &Msg); 
  virtual ~core_exception() throw();
  virtual const char *what() const throw();  
private: 
  std::string msg; 
}; 

# endif
