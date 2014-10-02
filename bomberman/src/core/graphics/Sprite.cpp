#include "core/graphics/Sprite.hpp"
#include "nds.h"

Sprite::Sprite()
{
}

Sprite::~Sprite() {}

void Sprite::setValue(SpriteSize size, SpriteColorFormat color, u8 *frameGfx, const unsigned short *spritePal, uint32 sizeSprite)
{
    this->frameGfx = frameGfx;
    gfxMem = oamAllocateGfx(&oamSub, size, color);
    dmaCopy(this->frameGfx, this->gfxMem, 16*16);
}

void Sprite::setTile(u8 * newFrameGfx, int x, int y, int id)
{
    this->frameGfx = newFrameGfx;
    dmaCopy(this->frameGfx, this->gfxMem, 16*16);
    oamSet(&oamSub, id, (x * 16) + 10 + x, (y * 16) + y, 0, 0xffffff, SpriteSize_16x16, SpriteColorFormat_256Color, this->gfxMem, -1, false, false, false, false, false);
}

void Sprite::hidden(int id)
{
    oamSet(&oamSub, id, 0, 0, 0, 0xffffff, SpriteSize_16x16, SpriteColorFormat_256Color, this->gfxMem, -1, false, true, false, false, false);
}