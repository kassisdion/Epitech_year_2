//
// map.hpp for map.hh in /home/faisant/Bureau/projet/cpp_nibbler/include/common
// 
// Made by florian faisant
// Login   <faisant@epitech.net>
// 
// Started on  Mon Mar 24 17:40:41 2014 florian faisant
// Last update Thu Apr  3 05:27:29 2014 florian faisant
//

#ifndef		MAP_H_
# define	MAP_H_

typedef enum	e_CaseType
  {
    SNAKE,
    FRUIT,
    EMPTY
  }		CaseType;

class		Map
{
public:
  Map(unsigned int width, unsigned int height);
  virtual ~Map();
public:
  virtual unsigned int	get_width() const;
  virtual unsigned int	get_height() const;
  virtual CaseType	**get_map();

private:
  unsigned int	width;
  unsigned int	height;
  CaseType	**map;
};

#endif
