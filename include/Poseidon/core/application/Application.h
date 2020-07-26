#pragma once

#include "Poseidon/core/application/Layer.h"
#include "Poseidon/core/events/EventDispatcher.h"
#include "Poseidon/core/events/EventHandler.h"
#include "Poseidon/core/events/KeyEvent.h"
#include "Poseidon/core/window/Window.h"

#include <memory>
#include <vector>

namespace poseidon {
    class Application : public EventHandler {
    public:
        Application(uint32_t windowWidth, uint32_t windowHeight, std::string windowTitle);
        virtual ~Application() = default;

        void start();
        void addLayer(Layer* layer);

        void handleEvent(Event* event) override;

    private:
        void handleKeyEvent(KeyEvent* event);

    public:

        [[noreturn]] void run();

    protected:
        std::unique_ptr<Window> m_window;
        std::vector<std::unique_ptr<Layer>> m_layers;
        EventDispatcher m_eventDispatcher;

        std::chrono::system_clock::time_point m_lastFrameTime;

        bool m_running = true;
    };

    extern Application *createApplication(int argc, char **argv);
}
