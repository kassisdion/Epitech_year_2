#include <nds.h>
#include "utils/time.hpp"

Timer::Timer(int timerID)
    : _timerID(timerID)
    , _elapsed(0)
{
    this->start();
}

Timer::~Timer()
{
    this->stop();
}

void Timer::start()
{
    timerStart(this->_timerID, ClockDivider_1024, 0, 0);
}

void Timer::pause()
{
    timerPause(this->_timerID);
}

void Timer::resume()
{
    timerUnpause(this->_timerID);
}

void Timer::stop()
{
    timerStop(this->_timerID);
}

Timer::time_t Timer::update()
{
    this->_elapsed += timerElapsed(this->_timerID);
    return this->_elapsed;
}

Timer::time_t Timer::consume()
{
    time_t elapsed = this->_elapsed;
    this->_elapsed = 0;
    return elapsed;
}

Timer::time_t Timer::elapsed()
{
    return this->_elapsed;
}

Timer &Timer::get(int timerID)
{
    static Timer timers[] = {
        Timer(0),
        Timer(1),
        Timer(2),
        Timer(3),
    };
    return timers[timerID];
}

Clock::Clock(Timer &timer)
    : timer(timer)
    , _start(timer.update())
{
}

Clock::~Clock()
{
}

Timer::time_t Clock::current(bool update)
{
    Timer::time_t current = update ? this->timer.update() : this->timer.elapsed();
    return current - this->_start;
}

void Clock::reset(bool update)
{
    this->_start = update ? this->timer.update() : this->timer.elapsed();
}
