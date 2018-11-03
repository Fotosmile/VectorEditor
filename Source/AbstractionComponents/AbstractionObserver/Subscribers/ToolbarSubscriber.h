//
// Created by Vlad on 09/10/18.
//

#ifndef ARCHITECTURE_TOOLBARSUBSCRIBER_H
#define ARCHITECTURE_TOOLBARSUBSCRIBER_H

#include "AbstractionObserver/ISubscriber.h"

class ToolbarSubscriber : public ISubscriber
{
public:
    void update(AbstractionState::StateType stateType) override;
};


#endif //ARCHITECTURE_TOOLBARSUBSCRIBER_H
