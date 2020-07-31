#pragma once

#include "Event.h"
#include "EventHandler.h"

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

        void dispatch(EventHandler* handler) override;
    };

    class KeyEventHandler : public EventHandler {
    public:
        virtual void handleEvent(const KeyEvent& event) = 0;
    };
}