#include <nds.h>
#include "core/screens.hpp"
#include "core/views/menu.hpp"
#include "core/bomberman.hpp"
#include "menu/main.hpp"

Bomberman::Bomberman()
    : controller(nullptr)
    , numIAs(5)
{
}

Bomberman::~Bomberman()
{
    delete this->controller;
}

void Bomberman::start()
{
    this->init();
    this->run();
}

void Bomberman::init()
{
    Screens::init();

    MenuView *view = new MenuView();
    Screens::lower().setView(view);
    view->setMenu(new MenuMain());
}

void Bomberman::run()
{
    while (true)
    {
        this->events();
        this->update();
        this->render();
    }
}

void Bomberman::events()
{
    _events.update();
}

void Bomberman::update()
{
    for (Bomberman::tick_fn_t tick_fn: this->tick_fns)
    {
        tick_fn();
    }
    this->tick_fns.clear();

    if (this->controller != nullptr)
    {
        this->controller->update(_events);
    }

    Screens::update(_events);
}

void Bomberman::render()
{
    Screens::render();
}

void Bomberman::setController(Controller *controller)
{
    Controller *old = this->controller;
    this->nextTick([old]() {
        delete old;
    });
    this->controller = controller;
}

void Bomberman::nextTick(Bomberman::tick_fn_t tick_fn)
{
    this->tick_fns.push_back(tick_fn);
}

Bomberman &Bomberman::getInstance()
{
    return *Bomberman::getInstancePtr();
}

Bomberman *Bomberman::getInstancePtr()
{
    static Bomberman instance;
    return &instance;
}
