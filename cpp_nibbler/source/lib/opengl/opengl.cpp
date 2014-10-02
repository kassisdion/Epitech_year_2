//
// lib_opengl.cpp for lib_opengl.cpp in /home/faisant/Bureau/projet/cpp_nibbler/source/lib/lib_opengl
// 
// Made by florian faisant
// Login   <faisant@epitech.net>
// 
// Started on  Mon Mar 24 15:36:08 2014 florian faisant
// Last update Sat Apr  5 18:47:43 2014 aude lejuez
//

#include	<SDL/SDL.h>
#include	<GL/gl.h>
#include	<GL/glut.h>
#include	<list>
#include	<string>
#include	<iostream>
#include	<sstream>
#include	"lib/opengl.hpp"
#include	"common/map.hpp"
#include	"common/event.hpp"

static		bool error(const std::string &msg)
{
  std::cout <<  msg << std::endl;
  return (false);
}

extern "C"
ILib			*createLib()
{
  return new OpenglLib();
}

OpenglLib::OpenglLib()
{

}

OpenglLib::~OpenglLib()
{
  SDL_Quit();
}

bool			OpenglLib::init(int height, int width)
{
  char			*argv[1];
  int			argc;

  argv[0] = strdup("nibbler");
  argc = 1;
  (void)height;
  (void)width;
  if (SDL_Init(SDL_INIT_VIDEO) == -1)
    return error("Ne peut lancer la SDL");
  glutInit(&argc, argv);
  this->window = SDL_SetVideoMode(800, 800, 32, SDL_OPENGL);
  if (this->window == NULL)
    return error("Ne peut crée une fenêtre");
  SDL_WM_SetCaption("Nibbler", NULL);
  SDL_EnableKeyRepeat(25,25);
  return true;
}

bool			OpenglLib::drawMap(Map &map)
{
  int			i;
  int			j;
  double		x;
  double		y;
  int			height;
  int			width;
  CaseType		**tmpMap;

  i = 0;
  height = map.get_height();
  width = map.get_width();
  tmpMap = map.get_map();
  glClear(GL_COLOR_BUFFER_BIT);
  y = 1;
  while (i < height)
    {
      j = 0;
      x = -1;	  
      while (j < width)
	{
	  switch (tmpMap[i][j])
	    {
	    case FRUIT:
	      glBegin(GL_QUADS);
	      glColor3ub(255, 0, 0);
	      glVertex2d(x , y);
	      glVertex2d(x , y - 2.0 / (double)height);
	      glColor3ub(255, 100, 0);
	      glVertex2d(x + 2.0 / (double)width, y - 2.0 / (double)height);
	      glVertex2d(x + 2.0 / (double)width, y);
	      glEnd();
	      break;
	    case SNAKE:
	      glBegin(GL_QUADS);
	      glColor3ub(0, 255, 0);
	      glVertex2d(x, y);
	      glVertex2d(x, y - 2.0 / (double)height);
	      glColor3ub(0, 255, 100);
	      glVertex2d(x + 2.0 / (double)width, y - 2.0 / (double)height);
	      glVertex2d(x + 2.0 / (double)width, y);
	      glEnd();
	      break;
	    case EMPTY:
	      break;
	    }
	  x += 2.0 / (double)width;
	  j++;
	}
      y -= 2.0 / (double)height; 
      i++;
    }
  glFlush();
  SDL_GL_SwapBuffers();
  return true;
}

std::list<EventType>	OpenglLib::pollEvent()
{
  std::list<EventType>	eventList;
  SDL_Event		event;

  while (SDL_PollEvent(&event));
  {
    if (event.type == SDL_QUIT)
      eventList.push_front(EXIT);
    switch (event.key.keysym.sym)
      {
      case SDLK_ESCAPE:
	eventList.push_front(EXIT);
	break;
      case SDLK_UP:
	eventList.push_front(UP);
	break;
      case SDLK_DOWN:
	eventList.push_front(DOWN);
	break;
      case SDLK_LEFT:
	eventList.push_front(LEFT);
	break;
      case SDLK_RIGHT:
	eventList.push_front(RIGHT);
	break;
      default:
	break;
      }
  }
  return eventList;
}

bool			OpenglLib::endGame(int score)
{
  std::ostringstream    scoring;
  SDL_Event		event;
  unsigned int		i;

  i = 0;
  scoring << "Game Over\n";
  glRasterPos2f(-1, 0.90);
  while (i < scoring.str().size())
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, (scoring.str())[i++]);
  scoring << "Score : \n" << score;
  glRasterPos2f(-1, 0.80);
  while (i < scoring.str().size())
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, (scoring.str())[i++]);
  scoring << "Continue ? (Y/n)\n";
  glRasterPos2f(-1, 0.70);
  while (i < scoring.str().size())
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, (scoring.str())[i++]);
  glFlush();
  SDL_GL_SwapBuffers();
  while (SDL_WaitEvent(&event))
    {
      if (event.type == SDL_QUIT)
	return false;
      switch(event.key.keysym.sym)
	{
	case SDLK_RETURN:
	  return true;
	  break;
	case SDLK_y:
	  return true;
	  break;
	case SDLK_n:
	  return false;
	  break;
	default:
	  break;
	}
    }
  return false;

}
