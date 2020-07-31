#pragma once

#include "Event.h"
#include "EventHandler.h"

namespace poseidon {
    struct MouseMovedData {
        double xPosition;
        double yPosition;
    };

    class MouseMovedEvent : public Event {
    public:
        explicit MouseMovedEvent(MouseMovedData data);

        void dispatch(EventHandler* handler) override;
    };

    class MouseMovedEventHandler : public EventHandler {
    public:
        virtual void handleEvent(const MouseMovedEvent& event) = 0;
    };


    enum class MouseButtonAction {
        Clicked,
        Released
    };

    enum class MouseButton {
        Left,
        Middle,
        Right
    };

    struct MouseButtonEventData {
        MouseButtonAction action;
        MouseButton button;
    };

    class MouseButtonEvent : public Event {
    public:
        explicit MouseButtonEvent(MouseButtonEventData data);

        void dispatch(EventHandler* handler) override;
    };

    class MouseButtonEventHandler : public EventHandler {
    public:
        virtual void handleEvent(const MouseButtonEvent& event) = 0;
    };


    struct MouseScrolledData {
        double xOffset;
        double yOffset;
    };

    class MouseScrolledEvent : public Event {
    public:
        explicit MouseScrolledEvent(MouseScrolledData data);

        void dispatch(EventHandler* handler) override;
    };

    class MouseScrolledEventHandler : public EventHandler {
    public:
        virtual void handleEvent(const MouseScrolledEvent& event) = 0;
    };
}