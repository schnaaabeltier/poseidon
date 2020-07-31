#include "Poseidon/core/events/MouseEvents.h"

poseidon::MouseMovedEvent::MouseMovedEvent(MouseMovedData data) : Event(data) {

}

void poseidon::MouseMovedEvent::dispatch(EventHandler* handler) {
    auto mouseEventHandler = dynamic_cast<MouseMovedEventHandler*>(handler);
    if (mouseEventHandler)
        mouseEventHandler->handleEvent(*this);
}


poseidon::MouseScrolledEvent::MouseScrolledEvent(MouseScrolledData data) : Event(data) {

}

void poseidon::MouseScrolledEvent::dispatch(EventHandler *handler) {
    auto mouseEventHandler = dynamic_cast<MouseScrolledEventHandler*>(handler);
    if (mouseEventHandler)
        mouseEventHandler->handleEvent(*this);
}


poseidon::MouseButtonEvent::MouseButtonEvent(MouseButtonEventData data) : Event(data) {

}

void poseidon::MouseButtonEvent::dispatch(EventHandler *handler) {
    auto mouseEventHandler = dynamic_cast<MouseButtonEventHandler*>(handler);
    if (mouseEventHandler)
        mouseEventHandler->handleEvent(*this);
}