//
// Created by Vlad on 09/10/18.
//

#ifndef ARCHITECTURE_TOOLBARSUBSCRIBER_H
#define ARCHITECTURE_TOOLBARSUBSCRIBER_H

#include "GUIObserver/Subscriber.h"

class ToolbarSubscriber : public Subscriber
{
public:
    void update(GUIState::StateType stateType) override;
};


#endif //ARCHITECTURE_TOOLBARSUBSCRIBER_H
