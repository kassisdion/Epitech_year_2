#ifndef MENUSETTINGS_HPP_
#define MENUSETTINGS_HPP_

#include    "core/menu.hpp"

class MenuSettings : public Menu
{
public:
  MenuSettings(MenuView *view = nullptr);
  virtual ~MenuSettings();

  virtual void    onClick(unsigned int index, MenuItem &item);
};

#endif
