//
// Created by Vlad on 09/10/18.
//

#ifndef ARCHITECTURE_ISUBSCRIBER_H
#define ARCHITECTURE_ISUBSCRIBER_H

#include "AbstractionState/AbstractionState.h"

class ISubscriber
{
public:
    virtual ~ISubscriber() = default;

    virtual void update(AbstractionState::StateType stateType) = 0;
};


#endif //ARCHITECTURE_ISUBSCRIBER_H
