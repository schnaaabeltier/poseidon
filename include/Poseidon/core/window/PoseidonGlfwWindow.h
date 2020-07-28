#pragma once

#include "Window.h"

#include <GLFW/glfw3.h>

namespace poseidon {
     class PoseidonGlfwWindow : public Window {
     public:
         PoseidonGlfwWindow(uint32_t width, uint32_t height, std::string title, EventDispatcher* dispatcher);
         ~PoseidonGlfwWindow() noexcept override;

         void onUpdate(std::chrono::milliseconds timeDelta) override;
         [[nodiscard]] std::any getNativeHandle() const override;

         void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

         [[nodiscard]] bool isDisplayed() const;

         static void onError(int error, const char *description);
         static KeyAction convertAction(int glfwAction);

     private:
         void initializeWindow();

         GLFWwindow *m_window = nullptr;
     };
}