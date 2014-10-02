//
// dl_lib.hpp for dl_lib.hpp in /home/faisant/Bureau/projet/cpp_nibbler
// 
// Made by florian faisant
// Login   <faisant@epitech.net>
// 
// Started on  Mon Mar 31 21:02:01 2014 florian faisant
// Last update Tue Apr  1 19:59:31 2014 florian faisant
//

#ifndef		DL_LIB_
# define	DL_LIB_

# include	"common/ilib.hpp"

class	Dl_library
{
public:
  Dl_library(const std::string &path);
  ILib *get_lib();
  ~Dl_library();
private:
  void	*handle;
};

#endif
