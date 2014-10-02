#include "nds.h"
#include "core/events.hpp"
#include "core/debug.hpp"

Events::Events()
    : a(false)
    , b(false)
    , x(false)
    , y(false)
    , l(false)
    , r(false)
    , start(false)
    , select(false)
    , up(false)
    , down(false)
    , left(false)
    , right(false)
    , touch(Touch{0,0,false})
{
}

Events::~Events()
{
}

void Events::update()
{
    touchPosition touch;
    int pressed;

    scanKeys();
    pressed = keysDown() | keysHeld();
    this->a = (pressed & KEY_A) != 0;
    this->b = (pressed & KEY_B) != 0;
    this->x = (pressed & KEY_X) != 0;
    this->y = (pressed & KEY_Y) != 0;
    this->l = (pressed & KEY_L) != 0;
    this->r = (pressed & KEY_R) != 0;
    this->start = (pressed & KEY_START) != 0;
    this->select = (pressed & KEY_SELECT) != 0;
    this->up = (pressed & KEY_UP) != 0;
    this->down = (pressed & KEY_DOWN) != 0;
    this->left = (pressed & KEY_LEFT) != 0;
    this->right = (pressed & KEY_RIGHT) != 0;
    touchRead(&touch);
    if (pressed & KEY_TOUCH)
        this->touch = Touch{touch.px, touch.py, true};
    else
        this->touch = Touch{0, 0, false};
}
