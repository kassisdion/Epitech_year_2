#ifndef CORE_MENU_H_
#define CORE_MENU_H_

#include <cstddef>
#include "nds.h"
#include "utils/geom/rect.hpp"

#define ARRAY_SIZE(array) (sizeof(array) / sizeof(*array))

class MenuView;

class Menu
{
public:
    class MenuItem
    {
    public:
        typedef Rect<unsigned int> ItemRect;

    public:
        inline MenuItem(ItemRect rect)
            : rect(rect)
        {}

    public:
        ItemRect rect;
    };

public:
    Menu(MenuItem *items, size_t nitems, MenuView *view = nullptr, const void *bgSrc = nullptr, const uint32 bgSize = 0);
    virtual ~Menu();

public:
    virtual void onClick(unsigned int index, MenuItem &item) {}

public:
    void onClick(Vec2u &pos);

public:
    void setView(MenuView *view = nullptr);
    MenuView &getView();
    const MenuView &getView() const;

public:
    MenuItem *items;
    size_t nitems;
    MenuView *view;
    const void *bgSrc;
    const uint32 bgSize;
};

#endif /* CORE_MENU_H_ */
