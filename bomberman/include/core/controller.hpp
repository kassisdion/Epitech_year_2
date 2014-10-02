#ifndef CORE_CONTROLLER_H_
#define CORE_CONTROLLER_H_

#include "core/events.hpp"

class Controller
{
public:
    Controller();
    virtual ~Controller();

public:
    virtual void update(const Events &events) {}
};

#endif /* CORE_CONTROLLER_H_ */
