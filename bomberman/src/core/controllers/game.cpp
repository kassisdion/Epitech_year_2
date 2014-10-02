#include "core/bomberman.hpp"
#include "core/controllers/game.hpp"
#include "core/debug.hpp"
#include "core/game/bomb.hpp"
#include "core/game/ia.hpp"
#include "core/screens.hpp"
#include "core/views/Graph3D.hpp"
#include "core/views/menu.hpp"
#include "core/views/miniMap.hpp"
#include "menu/main.hpp"
#include "menu/pause.hpp"
#include "menu/win.hpp"
#include "menu/loose.hpp"
#include "utils/geom/vec.hpp"
#include "WorldType/WorldType.hpp"

GameController::GameController(MiniMapView::TypeMap type, Game *_game)
  : game_ptr(_game)
  , game(*_game)
  , screenClock(Timer::get(0))
  , moveClock(Timer::get(0))
  , type(type)
{
  for (unsigned int i = 0; i < Bomberman::getInstance().numIAs; ++i)
    {
      Vec2u pos = this->game.map->randPos();
      IA *ia = new IA(this->game, pos);
      this->game.players.push_back(ia);
    }
}

GameController::GameController(MiniMapView::TypeMap type, Map *map)
    : GameController(type, new Game(map))
{
}

GameController::~GameController()
{
    delete this->game_ptr;
}

void GameController::update(const Events &events)
{
    if (events.select)
    {
        if (screenClock.current() > 4000)
        {
            screenClock.reset();
            if (this->game.pause)
            {
                this->resume();
            }
            else
            {
                this->pause();
            }
        }
    }

    if (!this->game.pause)
    {
        this->checkBombs();
        this->checkPlayers();
        this->doAction(events);
        this->doMove(events);

        if (this->game.getPlayer().isDead())
        {
            Bomberman::getInstance().nextTick([](){
                GameController::stop(false);
            });
            return;
        }
        else if  (this->game.players.size() == 1)
        {
            Bomberman::getInstance().nextTick([](){
                GameController::stop(true);
            });
            return;
        }
    }
}

void GameController::checkBombs()
{
  std::list<Bomb *> bombs = this->game.bombs;

  Timer::get(1).update();
  for (Bomb *bomb: bombs)
    {
      bomb->update();
    }
}

void GameController::checkPlayers()
{
    for (Player *player: this->game.players)
    {
        player->update();
    }
}

void GameController::doAction(const Events &events)
{
  if (events.l || events.r)
    {
      this->game.getPlayer().putBomb();
    }
}

void GameController::doMove(const Events &events)
{
  Vec2i diff(0, 0);

  if (events.up || events.x)
    {
      diff = Vec2i(0, 1);
    }

  if (events.down || events.b)
    {
      diff = Vec2i(0, -1);
    }

  if (events.right || events.a)
    {
      diff = Vec2i(1, 0);
    }

  if (events.left || events.y)
    {
      diff = Vec2i(-1, 0);
    }

  if (moveClock.current() > 4000)
    {
      this->game.getPlayer().moveDiff(diff);
      moveClock.reset();
    }
}

void GameController::pause()
{
    this->game.pause = true;

    Screens::lower().setView();
    Screens::lower().setMode(Screen::Mode::TwoD);
    Screens::lower().refresh();

    MenuView *view = new MenuView();
    MenuPause *menu = new MenuPause(*this);
    view->setMenu(menu);
    Screens::lower().setView(view);
}

void GameController::resume()
{
    Screens::lower().setMode(Screen::Mode::TwoD);
    MiniMapView *view = new MiniMapView(this->game, this->type, Screens::lower());
    Screens::lower().setView(view);

    this->game.pause = false;
}

void GameController::setup(Map *map, WorldType &world)
{
  GameController *controller = new GameController((MiniMapView::TypeMap)map->type, map);

  Bomberman::getInstance().setController(controller);

  Graph3D *graph3D = new Graph3D(controller->game);
  Screens::upper().setView(graph3D);
  graph3D->init();

  world.unload();
  world.load();

  Screens::lower().setMode(Screen::Mode::TwoD);
  MiniMapView *miniMap = new MiniMapView(controller->game, (MiniMapView::TypeMap)map->type, Screens::lower());
  Screens::lower().setView(miniMap);

  // Debug::init();
}

void GameController::stop(bool isWin)
{
    Screens::upper().setView();
    Screens::lower().setView();
    Bomberman::getInstance().setController();

    Screens::upper().setMode(Screen::Mode::TwoD);
    Screens::lower().setMode(Screen::Mode::TwoD);
    Screens::lower().refresh();

    MenuView *view = new MenuView();
    Screens::lower().setView(view);
    if (isWin == true)
        view->setMenu(new MenuWin());
    else
        view->setMenu(new MenuLoose());
}
