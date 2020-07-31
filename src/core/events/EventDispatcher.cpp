#include "Poseidon/core/events/EventDispatcher.h"
#include "Poseidon/core/logging/Logger.h"

void poseidon::EventDispatcher::handleEvents() {
    while (!m_queue.isEmpty()) {
        auto event = m_queue.getNextEvent();
        auto eventType = std::type_index(typeid(*event));
        for (auto handler : m_eventHandlers.at(eventType)) {
            event->dispatch(handler);
        }
    }
}

void poseidon::EventDispatcher::checkForEventType(std::type_index eventType) {
    if (!m_eventHandlers.contains(eventType))
        m_eventHandlers[eventType] = std::vector<EventHandler*>();
}