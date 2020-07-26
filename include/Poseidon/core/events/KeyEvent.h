#pragma once

#include "Event.h"

namespace poseidon {
    enum class KeyAction {
        Press,
        Repeat,
        Release
    };

    struct KeyEventData {
        int key;
        int scanCode;
        KeyAction action;
    };

    class KeyEvent : public Event {
    public:
        explicit KeyEvent(KeyEventData data);
    };
}