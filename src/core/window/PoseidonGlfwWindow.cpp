#include "Poseidon/core/events/KeyEvents.h"
#include "Poseidon/core/events/MouseEvents.h"
#include "Poseidon/core/events/WindowEvents.h"
#include "Poseidon/core/logging/Logger.h"
#include "Poseidon/core/window/PoseidonGlfwWindow.h"

#include <glbinding/glbinding.h>

poseidon::PoseidonGlfwWindow::PoseidonGlfwWindow(uint32_t width, uint32_t height, std::string title, EventDispatcher* dispatcher)
    : Window(width, height, std::move(title), dispatcher) {
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
    glfwSetWindowUserPointer(m_window, this);

    glfwSetKeyCallback(m_window, [](GLFWwindow* window, int key, int scanCode, int action, int mods) {
        auto appWindow = static_cast<PoseidonGlfwWindow*>(glfwGetWindowUserPointer(window));
        appWindow->keyCallback(window, key, scanCode, action, mods);
    });

    glfwSetCursorPosCallback(m_window, [](GLFWwindow* window, double xPos, double yPos) {
        auto appWindow = static_cast<PoseidonGlfwWindow*>(glfwGetWindowUserPointer(window));
        appWindow->cursorPositionCallback(window, xPos, yPos);
    });

    glfwSetMouseButtonCallback(m_window, [](GLFWwindow* window, int button, int action, int mods) {
        auto appWindow = static_cast<PoseidonGlfwWindow*>(glfwGetWindowUserPointer(window));
        appWindow->mouseButtonCallback(window, button, action, mods);
    });

    glfwSetScrollCallback(m_window, [](GLFWwindow* window, double xOffset, double yOffset) {
        auto appWindow = static_cast<PoseidonGlfwWindow*>(glfwGetWindowUserPointer(window));
        appWindow->scrollCallback(window, xOffset, yOffset);
    });

    glfwSetWindowSizeCallback(m_window, [](GLFWwindow* window, int width, int height) {
        auto appWindow = static_cast<PoseidonGlfwWindow*>(glfwGetWindowUserPointer(window));
        appWindow->resizeCallback(window, width, height);
    });

    glfwMakeContextCurrent(m_window);
    glbinding::initialize(glfwGetProcAddress);

    PS_CORE_INFO("Initialized GLFW window {} ({}x{})", getTitle(), getWidth(), getHeight());
}

void poseidon::PoseidonGlfwWindow::onError(int error, const char *description) {
    PS_CORE_ERROR("GLFW window error {}: {}", error, description);
}

void poseidon::PoseidonGlfwWindow::onUpdate(std::chrono::milliseconds timeDelta) {
    setVisible(!glfwWindowShouldClose(m_window));
    glfwPollEvents();
    glfwSwapBuffers(m_window);
}

void poseidon::PoseidonGlfwWindow::keyCallback(GLFWwindow *window, int key, int scanCode, int action, int mods) {
    auto eventData = KeyEventData {
        .key = key,
        .scanCode = scanCode,
        .action = convertKeyAction(action)
    };

    auto event = std::make_unique<KeyEvent>(eventData);
    m_eventDispatcher->dispatchEvent(std::move(event));
}

void poseidon::PoseidonGlfwWindow::cursorPositionCallback(GLFWwindow *window, double xPos, double yPos) {
    auto eventData = MouseMovedData {
        .xPosition = xPos,
        .yPosition = yPos
    };

    auto event = std::make_unique<MouseMovedEvent>(eventData);
    m_eventDispatcher->dispatchEvent(std::move(event));
}

void poseidon::PoseidonGlfwWindow::mouseButtonCallback(GLFWwindow *window, int button, int action, int mods) {
    auto eventData = MouseButtonEventData {
        .action = convertMouseButtonAction(action),
        .button = convertMouseButton(button)
    };

    auto event = std::make_unique<MouseButtonEvent>(eventData);
    m_eventDispatcher->dispatchEvent(std::move(event));
}

void poseidon::PoseidonGlfwWindow::scrollCallback(GLFWwindow *window, double xOffset, double yOffset) {
    auto eventData = MouseScrolledData {
        .xOffset = xOffset,
        .yOffset = yOffset
    };

    auto event = std::make_unique<MouseScrolledEvent>(eventData);
    m_eventDispatcher->dispatchEvent(std::move(event));
}

void poseidon::PoseidonGlfwWindow::resizeCallback(GLFWwindow *window, int width, int height) {
    auto eventData = WindowResizedEventData {
        .width = width,
        .height = height
    };

    auto event = std::make_unique<WindowResizedEvent>(eventData);
    m_eventDispatcher->dispatchEvent(std::move(event));
}

poseidon::KeyAction poseidon::PoseidonGlfwWindow::convertKeyAction(int glfwAction) {
    if (glfwAction == GLFW_PRESS)
        return KeyAction::Press;

    if (glfwAction == GLFW_RELEASE)
        return KeyAction::Release;

    return KeyAction::Repeat;
}

poseidon::MouseButton poseidon::PoseidonGlfwWindow::convertMouseButton(int glfwMouseButton) {
    if (glfwMouseButton == GLFW_MOUSE_BUTTON_LEFT)
        return MouseButton::Left;

    if (glfwMouseButton == GLFW_MOUSE_BUTTON_RIGHT)
        return MouseButton::Right;

    if (glfwMouseButton == GLFW_MOUSE_BUTTON_MIDDLE)
        return MouseButton::Middle;

    return MouseButton::Left;
}

poseidon::MouseButtonAction poseidon::PoseidonGlfwWindow::convertMouseButtonAction(int glfwAction) {
    if (glfwAction == GLFW_PRESS)
        return MouseButtonAction::Clicked;

    else return MouseButtonAction::Released;
}

std::any poseidon::PoseidonGlfwWindow::getNativeHandle() const {
    return m_window;
}
