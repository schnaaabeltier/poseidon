#pragma once

#include "EventHandler.h"
#include "EventQueue.h"

#include <functional>
#include <map>
#include <vector>

namespace poseidon {
    class EventDispatcher {
    public:
        void dispatchEvent(std::unique_ptr<Event> event);
        void addEventHandler(EventHandler* handler);
        void handleEvents();

    private:
        EventQueue m_queue;
        std::vector<EventHandler*> m_eventHandlers;
    };
}