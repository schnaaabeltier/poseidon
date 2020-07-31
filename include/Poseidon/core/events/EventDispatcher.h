#pragma once

#include "EventHandler.h"
#include "EventQueue.h"

#include <concepts>
#include <functional>
#include <map>
#include <typeindex>
#include <vector>

namespace poseidon {
    class EventDispatcher {
    public:
        template<typename EventType> requires IsEvent<EventType>
        void dispatchEvent(std::unique_ptr<EventType> event) {
            auto eventType = std::type_index(typeid(*event));
            checkForEventType(eventType);
            m_queue.addEvent(std::move(event));
        };

        template<typename EventType> requires IsEvent<EventType>
        void addEventHandler(EventHandler* handler) {
            auto eventType = std::type_index(typeid(EventType));
            checkForEventType(eventType);
            m_eventHandlers[eventType].push_back(handler);
        };

        void handleEvents();

    private:
        void checkForEventType(std::type_index eventType);

        EventQueue m_queue;
        std::map<std::type_index, std::vector<EventHandler*>> m_eventHandlers;
    };
}