//
// Created by Vlad on 09/10/18.
//

#ifndef ARCHITECTURE_EVENTMANAGER_H
#define ARCHITECTURE_EVENTMANAGER_H

#include <unordered_map>
#include <memory>

#include "IEventManager.h"
#include "AbstractionState/AbstractionState.h"

class ISubscriber;

class EventManager : public IEventManager
{
public:
    using mmapEventSubscriber_t =
            std::unordered_multimap<EventType, std::unique_ptr<ISubscriber>>;

    void subscribe(EventType eventType, std::unique_ptr<ISubscriber> subscriber) override;
    void unsubscribe(EventType eventType, std::unique_ptr<ISubscriber> subscriber) override;
    void notifySubscribers(EventType eventType, AbstractionState::StateType stateType) override;

private:
    mmapEventSubscriber_t m_subscribers;
};


#endif //ARCHITECTURE_EVENTMANAGER_H
