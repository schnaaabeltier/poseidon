#include "Poseidon/core/events/KeyEvents.h"
#include "Poseidon/core/logging/Logger.h"

poseidon::KeyEvent::KeyEvent(KeyEventData data) : Event(data) {

}

void poseidon::KeyEvent::dispatch(EventHandler* handler) {
    auto keyEventHandler = dynamic_cast<KeyEventHandler*>(handler);
    if (keyEventHandler)
        keyEventHandler->handleEvent(*this);
}

