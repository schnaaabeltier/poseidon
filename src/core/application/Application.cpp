#include "Poseidon/core/application/Application.h"
#include "Poseidon/core/logging/Logger.h"
#include "Poseidon/core/window/PoseidonGlfwWindow.h"

poseidon::Application::Application(uint32_t windowWidth, uint32_t windowHeight, std::string windowTitle) {
    m_window = std::make_unique<PoseidonGlfwWindow>(windowWidth, windowHeight, std::move(windowTitle), &m_eventDispatcher);
}

void poseidon::Application::start() {
    m_eventDispatcher.addEventHandler(this);
    run();
}

[[noreturn]] void poseidon::Application::run() {
    auto currentFrameTime = std::chrono::system_clock::now();
    auto timeDelta = std::chrono::duration_cast<std::chrono::milliseconds>(currentFrameTime - m_lastFrameTime);

    while(m_running) {
        m_eventDispatcher.handleEvents();

        for (auto &layer : m_layers) {
            layer->onUpdate(timeDelta);
        }

        m_window->onUpdate(timeDelta);
        m_running = m_window->isVisible();
    }

    m_lastFrameTime = currentFrameTime;
}

void poseidon::Application::addLayer(Layer *layer) {
    m_layers.push_back(std::unique_ptr<Layer>(layer));
}

void poseidon::Application::handleEvent(poseidon::Event* event) {
    if (event->getType() == "key_event")
        handleKeyEvent(dynamic_cast<KeyEvent*>(event));
}

void poseidon::Application::handleKeyEvent(poseidon::KeyEvent* event) {
    PS_CORE_INFO("Key event: {}", event->getData<KeyEventData>().key);
}
