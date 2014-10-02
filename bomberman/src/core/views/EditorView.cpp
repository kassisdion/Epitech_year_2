#include "core/debug.hpp"
#include "core/view.hpp"
#include "core/menu.hpp"
#include "core/screens.hpp"
#include "EditorMap/mapEditor.hpp"
#include "core/views/EditorView.hpp"
#include "graphics/map.h"
#include "graphics/fond.h"
#include "graphics/empty.h"
#include "graphics/editordwall.h"
#include "graphics/editoriwall.h"
#include "core/graphics/Sprite.hpp"
#include "core/debug.hpp"

EditorView::EditorView(MapEditor *mapEditor)
    : mapEditor(mapEditor)
    , x(0)
    , y(0)
    , clock(Timer::get(2))
{
    oamInit(&oamSub, SpriteMapping_1D_256, false);
    dmaCopy(mapBitmap, bgGetGfxPtr(Screens::lower().bg), mapBitmapLen);
    dmaCopy(fondBitmap, bgGetGfxPtr(Screens::upper().bg), fondBitmapLen);
    dmaCopy(emptyPal, SPRITE_PALETTE_SUB, emptyPalLen);
    sprites = new Sprite[14*9];
    for (int i = 0; i < 14*9; i++)
        sprites[i].setValue(SpriteSize_16x16, SpriteColorFormat_256Color, (u8*)emptyTiles, emptyPal, emptyPalLen);
    dwall = {(u8*)editordwallTiles, editordwallPal, editordwallPalLen};
    iwall = {(u8*)editoriwallTiles, editoriwallPal, editoriwallPalLen};
}

EditorView::~EditorView()
{
    delete sprites;
}

void EditorView::update(const Events &events)
{
    if (events.a)
        this->mapEditor->playWithMap();
    if (events.l)
        this->mapEditor->takeDestrWall();
    if (events.r)
        this->mapEditor->takeIndestrWall();
    if (events.b)
        this->mapEditor->backMenu();
    if (events.y)
        this->mapEditor->eraseMap();
    if (events.x)
        this->mapEditor->saveMap();
    if (events.touch.isTouch == true & this->clock.current() > 7000)
    {
        this->mapEditor->putWall(((events.touch.x - 10) / 17) + x, ((events.touch.y - 10) / 17) + y);
        this->clock.reset();
    }
    if (events.up)
        if (y > 0)
            y--;
    if (events.down)
        if (y < mapEditor->getHeight() - 9)
            y++;
    if (events.left)
        if (x > 0)
            x--;
    if (events.right)
        if (x < mapEditor->getWidth() - 14)
            x++;
}

void EditorView::render()
{
    swiWaitForVBlank();
    dmaCopy(mapBitmap, bgGetGfxPtr(Screens::lower().bg), mapBitmapLen);
//    dmaCopy(fondBitmap, bgGetGfxPtr(Screens::upper().bg), fondBitmapLen);
    int i = x;
    int j = y;
    int xMax = x + 13;
    int yMax = y + 8;
    int xSprite = 0;
    int ySprite = 0;
    int id = 0;

    while (j <= yMax)
    {
        xSprite = 0;
        i = x;
        while (i <= xMax)
        {
            if (this->mapEditor->_map->at(i, j) != Map::Tile::EMPTY)
            {
                affSprite(this->mapEditor->_map->at(i, j), xSprite, ySprite, id);
                id++;
            }
            i++;
            xSprite++;
        }
        j++;
        ySprite++;
    };
    while (id <= 14 * 9)
    {
        sprites[id].hidden(id);
        id++;
    }
    oamUpdate(&oamSub);
}

void EditorView::affSprite(Map::Tile tile, int x, int y, int id)
{
    switch (tile)
    {
        case Map::Tile::IWALL :
        sprites[id].frameGfx = this->iwall.frameGfx;
        dmaCopy(sprites[id].frameGfx, sprites[id].gfxMem, 16*16);
        oamSet(&oamSub, id, (x * 16) + 10 + x, (y * 16) + 10 + y, 0, 0xffffff, SpriteSize_16x16, SpriteColorFormat_256Color, sprites[id].gfxMem, -1, false, false, false, false, false);
        break;
        case Map::Tile::DWALL :
        sprites[id].frameGfx = this->dwall.frameGfx;
        dmaCopy(sprites[id].frameGfx, sprites[id].gfxMem, 16*16);
        oamSet(&oamSub, id, (x * 16) + 10 + x, (y * 16) + 10 + y, 0, 0xffffff, SpriteSize_16x16, SpriteColorFormat_256Color, sprites[id].gfxMem, -1, false, false, false, false, false);
        break;
    }
}
