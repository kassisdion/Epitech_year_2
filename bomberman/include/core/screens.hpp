#ifndef CORE_SCREENS_H_
#define CORE_SCREENS_H_

#include "core/screen.hpp"
#include "core/events.hpp"

class Screens
{
public:
    static void init();

public:
    static Screen &upper();
    static Screen &lower();

public:
    static void update(const Events &events);
    static void render();
};

#endif /* CORE_SCREENS_H_ */
