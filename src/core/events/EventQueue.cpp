#include "Poseidon/core/events/EventQueue.h"

void poseidon::EventQueue::addEvent(std::unique_ptr<Event> event) {
    m_eventQueue.push(std::move(event));
}

auto poseidon::EventQueue::getNextEvent() -> std::unique_ptr<Event> {
    auto event = std::move(m_eventQueue.front());
    m_eventQueue.pop();
    return std::move(event);
}

bool poseidon::EventQueue::isEmpty() const {
    return m_eventQueue.empty();
}