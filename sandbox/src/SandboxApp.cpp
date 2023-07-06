#include "SandboxApp.h"
#include "TestRenderLayer.h"

#include "Poseidon/Poseidon.h"

#include <iostream>

SandboxApp::SandboxApp(const std::string& assetsBasePath) : poseidon::Application(1920, 1080, "SandboxApp", assetsBasePath) {
    auto renderLayer = new TestRenderLayer();
    addLayer(renderLayer);
    auto imguiLayer = new poseidon::ImGuiLayer();
    addLayer(imguiLayer);
    PS_APP_INFO("Creating sandbox app.");
}

poseidon::Application *poseidon::createApplication(int argc, char **argv) {
    return new SandboxApp(argv[1]);
}
