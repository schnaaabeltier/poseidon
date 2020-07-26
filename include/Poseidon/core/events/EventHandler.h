#pragma once

namespace poseidon {
    class Event;

    class EventHandler {
    public:
        virtual void handleEvent(Event* event) = 0;
    };
}