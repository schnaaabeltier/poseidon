#include "Poseidon/core/events/EventDispatcher.h"
#include "Poseidon/core/logging/Logger.h"

void poseidon::EventDispatcher::dispatchEvent(std::unique_ptr<Event> event) {
    m_queue.addEvent(std::move(event));
}

void poseidon::EventDispatcher::addEventHandler(EventHandler* handler) {
    m_eventHandlers.push_back(handler);
}

void poseidon::EventDispatcher::handleEvents() {
    while (!m_queue.isEmpty()) {
        auto event = m_queue.getNextEvent();
        for (const auto& handler : m_eventHandlers) {
            handler->handleEvent(event.get());
        }
    }
}