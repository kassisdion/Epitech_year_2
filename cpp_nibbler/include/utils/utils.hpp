/*
** utils.h for utils in /home/faisant/Bureau/projet/cpp_nibbler/include/utils
** 
** Made by florian faisant
** Login   <faisant@epitech.net>
** 
** Started on  Thu Apr  3 06:46:14 2014 florian faisant
// Last update Thu Apr  3 07:04:37 2014 florian faisant
*/

#ifndef		UTILS_H
# define	UTILS_H

class		Coord
{
public:
  Coord(unsigned int x, unsigned int y);
  void set_coord(unsigned int x, unsigned int y);
  unsigned int get_x();
  unsigned int get_y();
private:
  unsigned int x;
  unsigned int y;
};

#endif
