#include "core/bomberman.hpp"
#include "core/debug.hpp"
#include "core/screen.hpp"
#include "nds.h"

Screen::Screen(View *view, Screen::Mode mode, Screen::Priority priority)
    : view(view)
    , mode(mode)
    , priority(priority)
{
    this->setMode(mode);
    this->refresh();
}

Screen::~Screen()
{
}

void Screen::setView(View *view)
{
    view->setScreen(this);
    View *old = this->view;
    Bomberman::getInstance().nextTick([old]() {
        delete old;
    });
    this->view = view;
}

View &Screen::getView()
{
    return *this->view;
}

void Screen::setMode(Screen::Mode mode)
{
    this->mode = mode;
    if (this->mode == Screen::Mode::ThreeD)
    {
        videoSetMode(MODE_0_3D);
        vramSetBankA(VRAM_A_TEXTURE);
        vramSetBankB(VRAM_B_TEXTURE);
    }
    else
    {
        if (this->priority == Screen::Priority::Primary)
        {
            vramSetBankA(VRAM_A_MAIN_BG);
            vramSetBankB(VRAM_B_MAIN_SPRITE);
            videoSetMode(MODE_5_2D);
        }
        else
        {
            vramSetBankC(VRAM_C_SUB_BG);
            vramSetBankD(VRAM_D_SUB_SPRITE);
            videoSetModeSub(MODE_5_2D);
        }
    }

}

Screen::Mode Screen::getMode() const
{
    return this->mode;
}

void Screen::switchMode()
{
    switch (this->mode)
    {
        case Screen::TwoD:
            this->setMode(Screen::ThreeD);
            break;

        case Screen::ThreeD:
            this->setMode(Screen::TwoD);
            break;
    }
}

void Screen::update(const Events &events)
{
    if (this->view != nullptr)
    {
        this->view->update(events);
    }
}

void Screen::render()
{
    if (this->view != nullptr)
    {
        this->view->render();
    }
}

void Screen::refresh()
{
    if (this->priority == Screen::Priority::Primary)
        this->bg = bgInit(3, BgType_Bmp16, BgSize_B16_256x256, 0, 0);
    else
        this->bg = bgInitSub(3, BgType_Bmp16, BgSize_B16_256x256, 0, 0);
}
