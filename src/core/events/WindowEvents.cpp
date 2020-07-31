#include "Poseidon/core/events/WindowEvents.h"

poseidon::WindowResizedEvent::WindowResizedEvent(WindowResizedEventData data) : Event(data) {

}

void poseidon::WindowResizedEvent::dispatch(EventHandler *handler) {
    auto windowHandler = dynamic_cast<WindowResizedEventHandler*>(handler);
    if (windowHandler)
        windowHandler->handleEvent(*this);
}