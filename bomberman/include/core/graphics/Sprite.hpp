#ifndef SPRITE
#define SPRITE

#include "nds.h"

class Sprite
{
    public:
        Sprite();
        ~Sprite();
        void setValue(SpriteSize size, SpriteColorFormat color, u8 *frameGfx, const unsigned short *spritePal, uint32 sizeSprite);
        void setTile(u8 * newFrameGfx, int x, int y, int id);
        void hidden(int id);

        u16* gfxMem;
        u8 *frameGfx;
};

struct SpriteTile
{
    u8 *frameGfx;
    const unsigned short *spritePal;
    uint32 sizeSprite;
};
#endif