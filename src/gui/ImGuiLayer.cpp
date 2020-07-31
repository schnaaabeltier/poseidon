#include "Poseidon/core/application/Application.h"
#include "Poseidon/core/logging/Logger.h"
#include "Poseidon/gui/ImGuiLayer.h"
#include "Poseidon/gui/glfw/ImGuiGLFWBinding.h"
#include "Poseidon/gui/glfw/ImGuiOpenGL3Binding.h"

#include <glbinding/gl/gl.h>

#include <cassert>

poseidon::ImGuiLayer::ImGuiLayer() : Layer("ImGuiLayer") {

}


void poseidon::ImGuiLayer::onAttach(Application& app) {
    app.getEventDispatcher().addEventHandler<KeyEvent>(static_cast<KeyEventHandler*>(this));
    app.getEventDispatcher().addEventHandler<MouseButtonEvent>(static_cast<MouseButtonEventHandler*>(this));
    app.getEventDispatcher().addEventHandler<MouseMovedEvent>(static_cast<MouseMovedEventHandler*>(this));
    app.getEventDispatcher().addEventHandler<MouseScrolledEvent>(static_cast<MouseScrolledEventHandler*>(this));
    app.getEventDispatcher().addEventHandler<WindowResizedEvent>(static_cast<WindowResizedEventHandler*>(this));

    auto window = std::any_cast<GLFWwindow*>(app.getWindow().getNativeHandle());
    assert(("Window was retrieved successfully.", window != nullptr));

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    std::filesystem::path fontFilePath = app.getAssetsBasePath() / "fonts" / "OpenSans-Regular.ttf";
    PS_CORE_INFO("Adding font file {}", fontFilePath.string());
    io.Fonts->AddFontFromFileTTF(fontFilePath.string().c_str(), 20);
    ImGui::StyleColorsDark();
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 430");
    ImGui::StyleColorsDark();
}

void poseidon::ImGuiLayer::onUpdate(std::chrono::milliseconds timeDelta) {
    gl::glClearColor(0, 0, 0, 1);
    gl::glClear(gl::ClearBufferMask::GL_COLOR_BUFFER_BIT);
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
    ImGui::ShowDemoWindow();
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void poseidon::ImGuiLayer::onDetach() {
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}

void poseidon::ImGuiLayer::handleEvent(const poseidon::KeyEvent& event) {

}

void poseidon::ImGuiLayer::handleEvent(const poseidon::MouseMovedEvent& event) {
    PS_CORE_INFO("Mouse moved x: {}", event.getData<MouseMovedData>().xPosition);
    PS_CORE_INFO("Mouse moved y: {}", event.getData<MouseMovedData>().yPosition);
}

void poseidon::ImGuiLayer::handleEvent(const poseidon::MouseButtonEvent& event) {
    PS_CORE_INFO("Mouse button event: {}, {}", event.getData<MouseButtonEventData>().button, event.getData<MouseButtonEventData>().action);
}

void poseidon::ImGuiLayer::handleEvent(const poseidon::MouseScrolledEvent& event) {
    PS_CORE_INFO("Mouse scrolled: {}, {}", event.getData<MouseScrolledData>().xOffset, event.getData<MouseScrolledData>().yOffset);
}

void poseidon::ImGuiLayer::handleEvent(const poseidon::WindowResizedEvent &event) {
    PS_CORE_INFO("Window resized: {} x {}", event.getData<WindowResizedEventData>().width, event.getData<WindowResizedEventData>().height);
}
