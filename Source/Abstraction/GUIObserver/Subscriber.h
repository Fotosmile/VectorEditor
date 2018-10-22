//
// Created by Vlad on 09/10/18.
//

#ifndef ARCHITECTURE_SUBSCRIBER_H
#define ARCHITECTURE_SUBSCRIBER_H

#include "GUIState/GUIState.h"

class Subscriber
{
public:
    virtual ~Subscriber() = default;

    virtual void update(GUIState::StateType stateType) = 0;
};


#endif //ARCHITECTURE_SUBSCRIBER_H
