#include    "core/controllers/game.hpp"
#include    "core/views/menu.hpp"
#include    "core/maps.hpp"
#include    "graphics/menuWorld.h"
#include    "menu/new_game.hpp"
#include    "menu/solo.hpp"
#include    "WorldType/ForestWorld.hpp"
#include    "WorldType/MarioWorld.hpp"
#include    "WorldType/SandWorld.hpp"
#include    "WorldType/SnowWorld.hpp"
#include    "WorldType/UrbanWorld.hpp"

static Menu::MenuItem *createItems()
{
    static Menu::MenuItem items[] = {
        Menu::MenuItem(Menu::MenuItem::ItemRect(20, 20, 50, 40)),
        Menu::MenuItem(Menu::MenuItem::ItemRect(100, 20, 50, 40)),
        Menu::MenuItem(Menu::MenuItem::ItemRect(180, 20, 50, 40)),
        Menu::MenuItem(Menu::MenuItem::ItemRect(50, 110, 50, 45)),
        Menu::MenuItem(Menu::MenuItem::ItemRect(150, 110, 50, 40)),
        Menu::MenuItem(Menu::MenuItem::ItemRect(210, 160, 40, 35)),
    };
    return items;
};

MenuNewGame::MenuNewGame(MenuView *view):
    Menu(createItems(), 6, view, menuWorldBitmap, menuWorldBitmapLen)
{
}

MenuNewGame::~MenuNewGame()
{
}

void    MenuNewGame::onClick(unsigned int index, MenuItem &item)
{
    switch (index)
    {
        case 0:
        {
            SandWorld world;
            Map *map = Map::load_str(map_test_width, map_test_height, map_test_data);
            map->type = Map::Type::SAND;
            GameController::setup(map, world);
        }
        break;

        case 1:
        {
            UrbanWorld world;
            Map *map = Map::load_str(map_test_width, map_test_height, map_test_data);
            map->type = Map::Type::URBAN;
            GameController::setup(map, world);
        }
        break;

        case 2:
        {
            ForestWorld world;;
            Map *map = Map::load_str(map_test_width, map_test_height, map_test_data);
            map->type = Map::Type::FOREST;
            GameController::setup(map, world);
        }
        break;

        case 3:
        {
            SnowWorld world;
            Map *map = Map::load_str(map_test_width, map_test_height, map_test_data);
            map->type = Map::Type::SNOW;
            GameController::setup(map, world);
        }
        break;

        case 4:
        {
            MarioWorld world;
            Map *map = Map::load_str(map_test_width, map_test_height, map_test_data);
            map->type = Map::Type::MARIO;
            GameController::setup(map, world);
        }
        break;

        case 5:
        {
            view->setMenu(new MenuSolo());
        }
        break;

        default:
        {
            // WTF. BUG BUG BUG !!!
        }
        break;
    }
}