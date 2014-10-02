#ifndef CORE_SCREEN_H_
#define CORE_SCREEN_H_

#include <cstdlib>
#include "core/view.hpp"
#include "core/events.hpp"

class Screen
{
public:
    enum Mode
    {
        TwoD,
        ThreeD,
    };

    enum Priority
    {
        Primary,
        Secondary,
    };
public:
    Screen(View *view = nullptr, Mode mode = TwoD, Priority priority = Secondary);
    ~Screen();

public:
    void setView(View *view = nullptr);
    View &getView();

    void setMode(Mode mode);
    Mode getMode() const;
    void switchMode();
    int bg;

public:
    void update(const Events &events);
    void render();

public:
    void refresh();

private:
    View *view;
    Mode mode;
    Priority priority;
};

#endif /* CORE_SCREEN_H_ */
