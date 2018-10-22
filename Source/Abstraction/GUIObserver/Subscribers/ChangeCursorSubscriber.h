//
// Created by Vlad on 09/10/18.
//

#ifndef ARCHITECTURE_CHANGE_CURSOR_SUBSCRIBER_H
#define ARCHITECTURE_CHANGE_CURSOR_SUBSCRIBER_H

#include "GUIObserver/Subscriber.h"

class ChangeCursorSubscriber : public Subscriber
{
public:
    void update(GUIState::StateType stateType) override;
};


#endif //ARCHITECTURE_CHANGE_CURSOR_SUBSCRIBER_H
