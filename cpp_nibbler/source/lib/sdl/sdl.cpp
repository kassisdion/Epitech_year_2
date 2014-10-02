//
// lib_sdl.cpp for lib_sdl.cpp in /home/faisant/Bureau/projet/cpp_nibbler/source/lib/lib_sdl
// 
// Made by florian faisant
// Login   <faisant@epitech.net>
// 
// Started on  Mon Mar 24 15:36:08 2014 florian faisant
// Last update Sat Apr  5 18:47:26 2014 aude lejuez
//

#include		<SDL/SDL.h>
#include		<SDL/SDL_image.h>
#include		<SDL/SDL_ttf.h>
#include		<list>
#include		<string>
#include		<iostream>
#include		<sstream>
#include		<unistd.h>
#include		"lib/sdl.hpp"
#include		"common/map.hpp"
#include		"common/event.hpp"


static			bool error(const std::string &msg)
{
  std::cout <<  msg << std::endl;
  return (false);
}

extern "C"
ILib			*createLib()
{
  return new SdlLib();
}

SdlLib::~SdlLib()
{
  TTF_Quit();
  if (this->fruit)
    SDL_FreeSurface(this->fruit);
  if (this->snake)
    SDL_FreeSurface(this->snake);
  if (this->background)
    SDL_FreeSurface(this->background);
  SDL_Quit();
}

SdlLib::SdlLib()
{
  this->fruit = NULL;
  this->snake = NULL;
  this->background = NULL;
}

bool			SdlLib::init(int width, int height)
{
  if (SDL_Init(SDL_INIT_VIDEO) == -1)
    return error("Ne peut lancer la SDL");
  if (TTF_Init() == -1)
    return error("Ne peut lancer la SDL_tff");
  this->window = SDL_SetVideoMode(width * 32, height * 32, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
  if (this->window == NULL)
    return error("Ne peut crée une fenêtre");
  SDL_WM_SetCaption("Nibbler", NULL);
  this->snake = IMG_Load("./resources/snake.png");
  this->fruit = IMG_Load("./resources/fruit.png");
  this->background = IMG_Load("./resources/background.png");
  if (!this->snake || !this->fruit || !this->fruit)
    return error("Ne peut initialiser les ressources");
  SDL_EnableKeyRepeat(25,25);
  SDL_Flip(this->window);
  return true;
}

bool			SdlLib::drawMap(Map &map)
{
  int			i;
  int			j;
  int			height;
  int			width;
  CaseType		**tmpMap;
  SDL_Rect		pos;

  i = 0;
  height = map.get_height();
  width = map.get_width();
  tmpMap = map.get_map();
  while (i < height)
    {
      j = 0;
      pos.y = i * 32;
      while (j < width)
	{
	  pos.x = j * 32;
	  if (SDL_BlitSurface(this->background, NULL, this->window, &pos) == -1)
	    return error("Ne peut afficher le fond");
	  switch (tmpMap[i][j])
	    {
	    case FRUIT:
	      if (SDL_BlitSurface(this->fruit, NULL, this->window, &pos) == -1)
		return error("Ne peut afficher le fruit");
	      break;
	    case SNAKE:
	      if (SDL_BlitSurface(this->snake, NULL, this->window, &pos) == -1)
		return error("Ne peut afficher le serpent");
	      break;
	    default:
	      break;
	    }
	  j++;
	}
      i++;
    }
  SDL_Flip(this->window);
  return true;
}

std::list<EventType>	SdlLib::pollEvent()
{
  std::list<EventType>	eventList;
  SDL_Event		event;

  while (SDL_PollEvent(&event))
    {
      if (event.type == SDL_QUIT)
	eventList.push_front(EXIT);
      switch(event.key.keysym.sym)
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

bool			SdlLib::endGame(int score)
{
  TTF_Font		*police;
  SDL_Surface		*text;
  SDL_Color		white;
  SDL_Rect		pos;
  SDL_Event		event;
  std::ostringstream	scoring;

  pos.x = 30;
  pos.y = 10;
  (void)score;
  white.r = 0;
  white.g = 0;
  white.b = 0;
  police = TTF_OpenFont("./resources/police.ttf", 70);
  if (police == NULL)
    return error("Ne peut charger la police");
  text = TTF_RenderText_Solid(police, "Game Over", white);
  if (SDL_BlitSurface(text, NULL, this->window, &pos) == -1)
    return error("Ne peut afficher l'écran de fin");
  pos.y += 30;
  scoring << "Score : " << score;
  text = TTF_RenderText_Solid(police, scoring.str().c_str(), white);
  if (SDL_BlitSurface(text, NULL, this->window, &pos) == -1)
    return error("Ne peut afficher l'écran de fin");
  pos.y += 30;
  text = TTF_RenderText_Solid(police, "Continue ? (Y/n)", white);
  if (SDL_BlitSurface(text, NULL, this->window, &pos) == -1)
    return error("Ne peut afficher l'écran de fin");
  SDL_Flip(this->window);
  TTF_CloseFont(police);
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
