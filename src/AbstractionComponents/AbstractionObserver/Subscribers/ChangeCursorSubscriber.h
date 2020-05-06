//
// Created by Vlad on 09/10/18.
//

#ifndef ARCHITECTURE_CHANGE_CURSOR_SUBSCRIBER_H
#define ARCHITECTURE_CHANGE_CURSOR_SUBSCRIBER_H

#include "AbstractionObserver/ISubscriber.h"

class ChangeCursorSubscriber : public ISubscriber
{
public:
    void update(AbstractionState::StateType stateType) override;
};


#endif //ARCHITECTURE_CHANGE_CURSOR_SUBSCRIBER_H
