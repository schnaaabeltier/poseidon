#include "Poseidon/core/logging/Logger.h"
#include "Poseidon/core/window/PoseidonGlfwWindow.h"

#include <glbinding/glbinding.h>

poseidon::PoseidonGlfwWindow::PoseidonGlfwWindow(uint32_t width, uint32_t height, std::string title) : Window(width, height, std::move(title)) {
    initializeWindow();
}

poseidon::PoseidonGlfwWindow::~PoseidonGlfwWindow() noexcept {
    glfwDestroyWindow(m_window);
    glfwTerminate();
}

void poseidon::PoseidonGlfwWindow::initializeWindow() {
    glfwSetErrorCallback(PoseidonGlfwWindow::onError);

    if (!glfwInit()) {
        PS_CORE_ERROR("Failed to initialize GLFW window {}", getTitle());
        glfwTerminate();
        return;
    }

    m_window = glfwCreateWindow(getWidth(), getHeight(), getTitle().c_str(), nullptr, nullptr);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    glfwMakeContextCurrent(m_window);
    glbinding::initialize(glfwGetProcAddress);

    PS_CORE_INFO("Initialized GLFW window {} ({}x{})", getTitle(), getWidth(), getHeight());
}

void poseidon::PoseidonGlfwWindow::onError(int error, const char *description) {
    PS_CORE_ERROR("GLFW window error {}: {}", error, description);
}

void poseidon::PoseidonGlfwWindow::onUpdate(std::chrono::milliseconds timeDelta) {
    glfwPollEvents();
    glfwSwapBuffers(m_window);
}
