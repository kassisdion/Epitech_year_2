#include "core/game/game.hpp"
#include "core/game/map.hpp"
#include "core/views/miniMap.hpp"
#include "core/views/menu.hpp"
#include "core/graphics/Sprite.hpp"
#include "core/screens.hpp"
#include "menu/pause.hpp"
#include "graphics/map.h"
#include "graphics/empty.h"
#include "graphics/AI.h"
#include "graphics/mariodwall.h"
#include "graphics/marioiwall.h"
#include "graphics/player.h"
#include "graphics/sanddwall.h"
#include "graphics/sandiwall.h"
#include "graphics/snowiwall.h"
#include "graphics/snowdwall.h"
#include "graphics/treeiwall.h"
#include "graphics/treedwall.h"
#include "graphics/urbandwall.h"
#include "graphics/urbaniwall.h"
#include "graphics/bomb.h"
#include "graphics/life.h"
#include "graphics/range.h"
#include "graphics/nbBomb.h"

#include "nds.h"

MiniMapView::MiniMapView(Game &miniMap, MiniMapView::TypeMap type, Screen &screen)
    : screen(screen)
    , miniMap(miniMap)
    , type(type)
{
    oamInit(&oamSub, SpriteMapping_1D_256, false);
    dmaCopy(mapBitmap, bgGetGfxPtr(Screens::lower().bg), mapBitmapLen);
    dmaCopy(emptyPal, SPRITE_PALETTE_SUB, emptyPalLen);
    sprites = new Sprite[14*10];
    for (int i = 0; i < 14*10; i++)
        sprites[i].setValue(SpriteSize_16x16, SpriteColorFormat_256Color, (u8*)emptyTiles, emptyPal, emptyPalLen);
    switch (type)
    {
        case MARIO:
            dwall = {(u8*)mariodwallTiles, mariodwallPal, mariodwallPalLen};
            iwall = {(u8*)marioiwallTiles, marioiwallPal, marioiwallPalLen};
        break;
        case FOREST:
            dwall = {(u8*)treedwallTiles, treedwallPal, treedwallPalLen};
            iwall = {(u8*)treeiwallTiles, treeiwallPal, treeiwallPalLen};
        break;
        case SNOW :
            dwall = {(u8*)snowdwallTiles, snowdwallPal, snowdwallPalLen};
            iwall = {(u8*)snowiwallTiles, snowiwallPal, snowiwallPalLen};
        break;
        case SAND :
            dwall = {(u8*)sanddwallTiles, sanddwallPal, sanddwallPalLen};
            iwall = {(u8*)sandiwallTiles, sandiwallPal, sandiwallPalLen};
        break;
        case URBAN :
            dwall = {(u8*)urbandwallTiles, urbandwallPal, urbandwallPalLen};
            iwall = {(u8*)urbaniwallTiles, urbaniwallPal, urbaniwallPalLen};
        break;
        default :
        //OUOUH ERROR !
        break;
    }
    empty = {(u8*)emptyTiles, emptyPal, emptyPalLen};
    player = {(u8*)playerTiles, playerPal, playerPalLen};
    AI = {(u8*)AITiles, AIPal, AIPalLen};
    bomb = {(u8*)bombTiles, bombPal, bombPalLen};
    life = {(u8*)lifeTiles, lifePal, lifePalLen};
    range = {(u8*)rangeTiles, rangePal, rangePalLen};
    nbBomb = {(u8*)nbBombTiles, nbBombPal, nbBombPalLen};
}

 MiniMapView::~MiniMapView(){}

void MiniMapView::update(const Events &events)
{
}

void MiniMapView::render()
{
    int x = this->miniMap.getPlayer().getPos().x() - 7;
    int y = this->miniMap.getPlayer().getPos().y() - 5;
    int xMax = this->miniMap.getPlayer().getPos().x() + 6;
    int yMax = this->miniMap.getPlayer().getPos().y() + 4;
    int xSprite = 0;
    int ySprite = 10;
    int id = 0;

    while (y <= yMax)
    {
        xSprite = 0;
        x = this->miniMap.getPlayer().getPos().x() - 7;
        while (x <= xMax)
        {
            if (this->miniMap.map->at(x, y) != Map::Tile::EMPTY)
            {
                affSprite(this->miniMap.map->at(x, y), xSprite, ySprite, id);
                id++;
            }
            x++;
            xSprite++;
        }
        y++;
        ySprite--;
    };
    sprites[id].setTile(this->player.frameGfx, 7, 5, id);
    id++;
    for (int i = 0; i < this->miniMap.getPlayer().nbBombs; i++)
    {
        sprites[id].setTile(this->bomb.frameGfx, i, 0, id);
        id++;
    }
    for (int i = 0; i < this->miniMap.getPlayer().life; i++)
    {
        sprites[id].setTile(this->life.frameGfx, 13 - i, 0, id);
        id++;
    }
    while (id <= 14 * 10)
    {
        sprites[id].hidden(id);
        id++;
    }
    oamUpdate(&oamSub);
}

void MiniMapView::affSprite(Map::Tile tile, int x, int y, int id)
{
    switch (tile)
    {
        case Map::Tile::IWALL :
        sprites[id].setTile(this->iwall.frameGfx, x, y, id);
        break;
        case Map::Tile::DWALL :
        sprites[id].setTile(this->dwall.frameGfx, x, y, id);
        break;
        case Map::Tile::LIFE :
        sprites[id].setTile(this->life.frameGfx, x, y, id);
        break;
        case Map::Tile::BOMB :
        sprites[id].setTile(this->nbBomb.frameGfx, x, y, id);
        break;
        case Map::Tile::RANGE :
        sprites[id].setTile(this->range.frameGfx, x, y, id);
        break;
    }
}