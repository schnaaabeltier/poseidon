#include "Poseidon/core/application/Application.h"
#include "Poseidon/core/logging/Logger.h"
#include "Poseidon/gui/ImGuiLayer.h"
#include "Poseidon/gui/glfw/ImGuiGLFWBinding.h"
#include "Poseidon/gui/glfw/ImGuiOpenGL3Binding.h"

#include <glbinding/gl/gl.h>

#include <cassert>

poseidon::ImGuiLayer::ImGuiLayer() : Layer("ImGuiLayer") {

}


void poseidon::ImGuiLayer::onAttach(const Application& app) {
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
