#ifndef CORE_VIEW_H_
#define CORE_VIEW_H_

#include "core/events.hpp"

class Screen;

class View
{
public:
    View(Screen *screen = nullptr);
    virtual ~View();

public:
    virtual void update(const Events &events) {}
    virtual void render() = 0;

public:
    void setScreen(Screen *screen = nullptr);
    Screen &getScreen();
    const Screen &getScreen() const;

protected:
    Screen *screen;
};

#endif /* CORE_VIEW_H_ */
