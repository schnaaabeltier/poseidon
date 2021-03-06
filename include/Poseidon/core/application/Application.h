#pragma once

#include "Poseidon/core/application/Layer.h"
#include "Poseidon/core/events/EventDispatcher.h"
#include "Poseidon/core/events/EventHandler.h"
#include "Poseidon/core/events/KeyEvents.h"
#include "Poseidon/core/window/Window.h"

#include <filesystem>
#include <memory>
#include <vector>

namespace poseidon {
    class Application : public KeyEventHandler {
    public:
        Application(uint32_t windowWidth, uint32_t windowHeight, std::string windowTitle, const std::string& assetsBasePath);
        virtual ~Application() = default;

        void start();
        void addLayer(Layer* layer);

        void handleEvent(const KeyEvent& event) override;

        [[nodiscard]] const Window& getWindow() const;
        [[nodiscard]] std::filesystem::path getAssetsBasePath() const;
        [[nodiscard]] EventDispatcher& getEventDispatcher();
        void run();

    protected:
        std::unique_ptr<Window> m_window;
        std::vector<std::unique_ptr<Layer>> m_layers;
        EventDispatcher m_eventDispatcher;

        std::chrono::system_clock::time_point m_lastFrameTime;

        bool m_running = true;

        std::filesystem::path m_assetsBasePath;
    };

    extern Application *createApplication(int argc, char **argv);
}
