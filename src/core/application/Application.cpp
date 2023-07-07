#include "Poseidon/core/application/Application.h"
#include "Poseidon/core/logging/Logger.h"
#include "Poseidon/core/window/PoseidonGlfwWindow.h"
#include "Poseidon/gui/ImGuiLayer.h"

poseidon::Application::Application(uint32_t windowWidth, uint32_t windowHeight, std::string windowTitle, const std::string& assetsBasePath) {
    m_window = std::make_unique<PoseidonGlfwWindow>(windowWidth, windowHeight, std::move(windowTitle), &m_eventDispatcher);
    m_assetManager = std::make_unique<AssetManager>(assetsBasePath);
}

void poseidon::Application::start() {
    m_eventDispatcher.addEventHandler<KeyEvent>(this);
    run();
}

void poseidon::Application::run() {
    while(m_running) {
        auto currentFrameTime = std::chrono::system_clock::now();
        auto timeDelta = std::chrono::duration_cast<std::chrono::milliseconds>(currentFrameTime - m_lastFrameTime);
        m_eventDispatcher.handleEvents();

        for (auto &layer : m_layers) {
            layer->onUpdate(RenderingContext {
                .timeDelta = timeDelta,
                .assetManager = *m_assetManager,
            });
        }

        m_window->onUpdate(timeDelta);
        m_running = m_window->isVisible();
        m_lastFrameTime = currentFrameTime;
    }
}

void poseidon::Application::addLayer(Layer *layer) {
    m_layers.push_back(std::unique_ptr<Layer>(layer));
    layer->onAttach(*this);
}

void poseidon::Application::handleEvent(const KeyEvent &event) {

}

const poseidon::Window& poseidon::Application::getWindow() const {
    return *m_window;
}

poseidon::AssetManager& poseidon::Application::getAssetManager() const
{
    return *m_assetManager;
}

poseidon::EventDispatcher& poseidon::Application::getEventDispatcher() {
    return m_eventDispatcher;
}
