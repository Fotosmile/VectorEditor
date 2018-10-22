//
// Created by Vlad on 09/10/18.
//

#ifndef ARCHITECTURE_SHOWNOTIFICATIONSUBSCRIBER_H
#define ARCHITECTURE_SHOWNOTIFICATIONSUBSCRIBER_H

#include "GUIObserver/Subscriber.h"

class ShowNotificationSubscriber : public Subscriber
{
public:
    void update(GUIState::StateType stateType) override;
};


#endif //ARCHITECTURE_SHOWNOTIFICATIONSUBSCRIBER_H
