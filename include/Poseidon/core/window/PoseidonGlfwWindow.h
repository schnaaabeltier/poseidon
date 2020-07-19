#pragma once

#include "Window.h"

#include <GLFW/glfw3.h>

namespace poseidon {
     class PoseidonGlfwWindow : public Window {
     public:
         PoseidonGlfwWindow(uint32_t width, uint32_t height, std::string title);
         ~PoseidonGlfwWindow() noexcept override;

         void onUpdate(std::chrono::milliseconds timeDelta) override;

         static void onError(int error, const char *description);

     private:
         void initializeWindow();

         GLFWwindow *m_window = nullptr;
     };
}