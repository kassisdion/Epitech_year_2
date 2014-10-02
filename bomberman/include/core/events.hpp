#ifndef CORE_EVENTS_H_
#define CORE_EVENTS_H_

struct Touch
{
public:
    unsigned int x;
    unsigned int y;
    bool isTouch;

};

class Events
{
public:
    Events();
    ~Events();

public:
    void update();

    bool a;
    bool b;
    bool x;
    bool y;
    bool l;
    bool r;
    bool start;
    bool select;
    bool up;
    bool down;
    bool right;
    bool left;
    Touch touch;
};

#endif /* CORE_EVENTS_H_ */
