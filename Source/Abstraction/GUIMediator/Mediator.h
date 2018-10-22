//
// Created by Vlad on 09/10/18.
//

#ifndef ARCHITECTURE_MEDIATOR_H
#define ARCHITECTURE_MEDIATOR_H

class ControlElement;

class Mediator
{
public:
    virtual ~Mediator() = default;

    virtual void notify(ControlElement * controlElement) = 0;
};


#endif //ARCHITECTURE_MEDIATOR_H
