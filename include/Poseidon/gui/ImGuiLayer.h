#pragma once

#include "Poseidon/core/application/Layer.h"
#include "Poseidon/core/window/Window.h"

namespace poseidon {
    class ImGuiLayer : public Layer {
    public:
        ImGuiLayer();
        ~ImGuiLayer() override = default;

        void onAttach(const Application& app) override;
        void onUpdate(std::chrono::milliseconds timeDelta) override;
        void onDetach() override;
    };
}