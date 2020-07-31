#pragma once

#include "Window.h"
#include "Poseidon/core/events/KeyEvents.h"
#include "Poseidon/core/events/MouseEvents.h"

#include <GLFW/glfw3.h>

namespace poseidon {
     class PoseidonGlfwWindow : public Window {
     public:
         PoseidonGlfwWindow(uint32_t width, uint32_t height, std::string title, EventDispatcher* dispatcher);
         ~PoseidonGlfwWindow() noexcept override;

         void onUpdate(std::chrono::milliseconds timeDelta) override;
         [[nodiscard]] std::any getNativeHandle() const override;

         void keyCallback(GLFWwindow* window, int key, int scanCode, int action, int mods);
         void cursorPositionCallback(GLFWwindow* window, double xPos, double yPos);
         void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
         void scrollCallback(GLFWwindow* window, double xOffset, double yOffset);
         void resizeCallback(GLFWwindow* window, int width, int height);

         static void onError(int error, const char *description);
         static KeyAction convertKeyAction(int glfwAction);
         static MouseButton convertMouseButton(int glfwMouseButton);
         static MouseButtonAction convertMouseButtonAction(int glfwAction);

     private:
         void initializeWindow();

         GLFWwindow *m_window = nullptr;
     };
}