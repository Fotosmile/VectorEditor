//
// Created by Vlad on 25/10/18.
//

#ifndef ARCHITECTURE_IEVENTMANAGER_H
#define ARCHITECTURE_IEVENTMANAGER_H

#include <memory>

#include "AbstractionState/AbstractionState.h"

class ISubscriber;

class IEventManager
{
public:
    enum class EventType {StateChanged};

    virtual ~IEventManager() = default;

    virtual void subscribe(EventType eventType, std::unique_ptr<ISubscriber> subscriber) = 0;
    virtual void unsubscribe(EventType eventType, std::unique_ptr<ISubscriber> subscriber) = 0;
    virtual void notifySubscribers(EventType eventType, AbstractionState::StateType stateType) = 0;
};


#endif //ARCHITECTURE_IEVENTMANAGER_H
