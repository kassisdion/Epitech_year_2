#ifndef CORE_VIEWS_MINIMAP_H_
#define CORE_VIEWS_MINIMAP_H_

#include "core/screen.hpp"
#include "core/view.hpp"
#include "core/menu.hpp"
#include "core/game/game.hpp"
#include "core/graphics/Sprite.hpp"
#include "core/events.hpp"

class MiniMap;

class MiniMapView: public View
{
public:
    enum TypeMap
    {
        MARIO = 0,
        FOREST = 1,
        SNOW = 2,
        SAND = 3,
        URBAN = 4,
    };

public:
    MiniMapView(Game &menu, MiniMapView::TypeMap type, Screen &screen);
    ~MiniMapView();
public:
    virtual void update(const Events &events);
    virtual void render();

public:
    void    affSprite(Map::Tile tile, int x, int y, int id);

private:
    Game miniMap;
    TypeMap type;
    Sprite *sprites;
    Screen &screen;
    SpriteTile iwall;
    SpriteTile dwall;
    SpriteTile player;
    SpriteTile AI;
    SpriteTile bomb;
    SpriteTile empty;
    SpriteTile life;
    SpriteTile nbBomb;
    SpriteTile range;
};

#endif /* CORE_VIEWS_MINIMAP_H_ */
