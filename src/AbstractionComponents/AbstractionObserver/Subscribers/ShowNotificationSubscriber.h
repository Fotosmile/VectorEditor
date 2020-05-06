//
// Created by Vlad on 09/10/18.
//

#ifndef ARCHITECTURE_SHOWNOTIFICATIONSUBSCRIBER_H
#define ARCHITECTURE_SHOWNOTIFICATIONSUBSCRIBER_H

#include "AbstractionObserver/ISubscriber.h"

class ShowNotificationSubscriber : public ISubscriber
{
public:
    void update(AbstractionState::StateType stateType) override;
};


#endif //ARCHITECTURE_SHOWNOTIFICATIONSUBSCRIBER_H
