#ifndef CORE_BOMBERMAN_H_
#define CORE_BOMBERMAN_H_

#include <vector>
#include <functional>
#include "core/events.hpp"
#include "core/controller.hpp"

class Bomberman
{
public:
    typedef std::function<void()> tick_fn_t;

public:
    Bomberman();
    ~Bomberman();

public:
    void start();

private:
    void init();
    void run();

private:
    void events();
    void update();
    void render();

public:
    void setController(Controller *controller = nullptr);

public:
    void nextTick(tick_fn_t tick_fn);

private:
    Events _events;
    Controller *controller;

    std::vector<tick_fn_t> tick_fns;

public:
    unsigned int numIAs;

public:
    static Bomberman &getInstance();

private:
    static Bomberman *getInstancePtr();
};

#endif /* CORE_BOMBERMAN_H_ */
