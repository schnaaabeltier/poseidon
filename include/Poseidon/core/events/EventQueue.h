#pragma once

#include "Poseidon/core/events/Event.h"

#include <memory>
#include <queue>

namespace poseidon {
    class EventQueue {
    public:
        void addEvent(std::unique_ptr<Event> event);
        std::unique_ptr<Event> getNextEvent();

        [[nodiscard]] bool isEmpty() const;

    private:
        std::queue<std::unique_ptr<Event>> m_eventQueue;
    };
}