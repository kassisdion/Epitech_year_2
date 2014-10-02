//
// nibler.hpp for nibler in /home/faisant/Bureau/projet/cpp_nibbler/include/core
// 
// Made by florian faisant
// Login   <faisant@epitech.net>
// 
// Started on  Mon Mar 24 15:41:31 2014 florian faisant
// Last update Sat Apr  5 11:36:10 2014 florian faisant
//

#ifndef		NIBBLER_HPP
# define	NIBBLER_HPP

# include	<string>
# include	"common/map.hpp"
# include	"core/dl_lib.hpp"
# include	"core/snake.hpp"
# include	"core/fruit.hpp"

class		Nibbler
{
public:
  Nibbler(int width, int height, const std::string &path);
  ~Nibbler();
  void          run(int width, int height);
private:
  bool		check_event();
  bool		action();
private:
  Map		map;
  Dl_library	dl_lib;
  ILib		*lib;
  Snake		snake;
  Fruit		fruit;
  int		speed;
  int		score;
};

#endif
