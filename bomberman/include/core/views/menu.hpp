#ifndef CORE_VIEWS_MENU_H_
#define CORE_VIEWS_MENU_H_

#include "core/view.hpp"
#include "core/menu.hpp"
#include "utils/time.hpp"

class MenuView: public View
{
public:
    MenuView(Screen *screen = nullptr, Menu *menu = nullptr);
    virtual ~MenuView();

public:
    virtual void update(const Events &events);
    virtual void render();

public:
    void setMenu(Menu *menu = nullptr);
    Menu &getMenu();
    const Menu &getMenu() const;

protected:
    Menu *menu;
    Clock clock;
};

#endif /* CORE_VIEWS_MENU_H_ */
