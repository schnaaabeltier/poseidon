#pragma once

#include "Event.h"
#include "EventHandler.h"

namespace poseidon {
    struct WindowResizedEventData {
        int width;
        int height;
    };

    class WindowResizedEvent : public Event {
    public:
        explicit WindowResizedEvent(WindowResizedEventData data);

        void dispatch(EventHandler* handler) override;
    };

    class WindowResizedEventHandler : public EventHandler {
    public:
        virtual void handleEvent(const WindowResizedEvent& event) = 0;
    };
}