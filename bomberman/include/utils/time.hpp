#ifndef UTILS_TIME_H_
#define UTILS_TIME_H_

#include "nds/ndstypes.h"

class Timer
{
public:
    typedef u16 time_t;

public:
    Timer(int timerID);
    ~Timer();

public:
    void start();
    void pause();
    void resume();
    void stop();

    time_t update();
    time_t consume();

    time_t elapsed();

private:
    int _timerID;
    time_t _elapsed;

public:
    static Timer &get(int timerID);
};

class Clock
{
public:
    Clock(Timer &timer);
    ~Clock();

public:
    Timer::time_t current(bool update = true);
    void reset(bool update = true);

private:
    Timer::time_t _start;
    Timer &timer;
};

#endif /* UTILS_TIME_H_ */
