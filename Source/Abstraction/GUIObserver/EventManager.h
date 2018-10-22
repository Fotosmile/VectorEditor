//
// Created by Vlad on 09/10/18.
//

#ifndef ARCHITECTURE_EVENTMANAGER_H
#define ARCHITECTURE_EVENTMANAGER_H

#include <unordered_map>
#include <memory>

#include "GUIState/GUIState.h"
#include "Subscriber.h"

class EventManager
{
public:
    enum class EventType {StateChanged};

    using mmapEventSubscriber_t =
            std::unordered_multimap<EventType, std::unique_ptr<Subscriber>>;

    void subscribe(EventType eventType, std::unique_ptr<Subscriber> subscriber);
    void unsubscribe(EventType eventType, std::unique_ptr<Subscriber> subscriber);
    void notifySubscribers(EventType eventType, GUIState::StateType stateType);

private:
    mmapEventSubscriber_t m_subscribers;
};


#endif //ARCHITECTURE_EVENTMANAGER_H
