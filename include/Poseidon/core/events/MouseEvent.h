#pragma once

#include "Event.h"

namespace poseidon {
    struct MouseMovedData {
        double xPosition;
        double yPosition;
    };

    class MouseMovedEvent : public Event {
    public:
        explicit MouseMovedEvent(MouseMovedData data);
    };
}