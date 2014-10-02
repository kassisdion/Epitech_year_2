#ifndef CORE_CONTROLLERS_GAME_H_
#define CORE_CONTROLLERS_GAME_H_

#include "core/controller.hpp"
#include "core/events.hpp"
#include "core/game/game.hpp"
#include "core/game/map.hpp"
#include "core/views/miniMap.hpp"
#include "WorldType/WorldType.hpp"

class GameController: public Controller
{
public:
    GameController(MiniMapView::TypeMap type, Game *game);
    GameController(MiniMapView::TypeMap type, Map *map = nullptr);
    virtual ~GameController();

public:
    virtual void update(const Events &events);

private:
    void checkBombs();
    void checkPlayers();
    void doAction(const Events &events);
    void doMove(const Events &events);

public:
    void pause();
    void resume();

public:
    /**
     * Setup controller and views for Bomberman.
     */
    static void setup(Map *map, WorldType &world);
    static void stop(bool isWin);

public:
    Game &game;
    Game *game_ptr;
    Clock screenClock;
    Clock moveClock;
    MiniMapView::TypeMap type;
};

#endif /* CORE_CONTROLLERS_GAME_H_ */
