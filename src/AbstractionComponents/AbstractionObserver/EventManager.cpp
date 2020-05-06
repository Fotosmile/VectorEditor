//
// Created by Vlad on 09/10/18.
//

#include <algorithm>
#include <stdexcept>

#include "EventManager.h"
#include "ISubscriber.h"

void EventManager::subscribe(EventManager::EventType eventType, std::unique_ptr<ISubscriber> subscriber)
{
    m_subscribers.insert(std::make_pair(eventType, std::move(subscriber)));
}

void EventManager::unsubscribe(EventManager::EventType eventType, std::unique_ptr<ISubscriber> subscriber)
{
    auto it = std::find(m_subscribers.begin(), m_subscribers.end(),
                        mmapEventSubscriber_t::value_type(eventType, std::move(subscriber)));
    if (it == m_subscribers.end())
    {
        throw std::invalid_argument("Failed to unsubscribe the not subscribed object");
    }
    m_subscribers.erase(it);
}

void EventManager::notifySubscribers(EventManager::EventType eventType, AbstractionState::StateType stateType)
{
    for (auto it = m_subscribers.find(eventType); it != m_subscribers.end(); ++it)
    {
        it->second->update(stateType);
    }
}