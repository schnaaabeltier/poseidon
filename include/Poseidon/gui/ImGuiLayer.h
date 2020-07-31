#pragma once

#include "Poseidon/core/application/Layer.h"
#include "Poseidon/core/events/KeyEvents.h"
#include "Poseidon/core/events/MouseEvents.h"
#include "Poseidon/core/events/WindowEvents.h"
#include "Poseidon/core/window/Window.h"

namespace poseidon {
    class ImGuiLayer : public Layer, public KeyEventHandler, public MouseButtonEventHandler, public MouseScrolledEventHandler,
            public MouseMovedEventHandler, public WindowResizedEventHandler {
    public:
        ImGuiLayer();
        ~ImGuiLayer() override = default;

        void onAttach(Application& app) override;
        void onUpdate(std::chrono::milliseconds timeDelta) override;
        void onDetach() override;

        void handleEvent(const KeyEvent &event) override;
        void handleEvent(const MouseMovedEvent &event) override;
        void handleEvent(const MouseButtonEvent &event) override;
        void handleEvent(const MouseScrolledEvent &event) override;
        void handleEvent(const WindowResizedEvent& event) override;
    };
}