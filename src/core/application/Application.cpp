#include "Poseidon/core/application/Application.h"
#include "Poseidon/core/logging/Logger.h"
#include "Poseidon/core/window/PoseidonGlfwWindow.h"

poseidon::Application::Application(uint32_t windowWidth, uint32_t windowHeight, std::string windowTitle) {
    m_window = std::make_unique<PoseidonGlfwWindow>(windowWidth, windowHeight, std::move(windowTitle));
}

void poseidon::Application::start() {
    run();
}

[[noreturn]] void poseidon::Application::run() {
    auto currentFrameTime = std::chrono::system_clock::now();
    auto timeDelta = std::chrono::duration_cast<std::chrono::milliseconds>(currentFrameTime - m_lastFrameTime);

    while(m_running) {
        for (auto &layer : m_layers) {
            layer->onUpdate(timeDelta);
        }

        m_window->onUpdate(timeDelta);
    }

    m_lastFrameTime = currentFrameTime;
}

void poseidon::Application::addLayer(Layer *layer) {
    m_layers.push_back(std::unique_ptr<Layer>(layer));
}