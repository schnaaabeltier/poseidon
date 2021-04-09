#pragma once

#include "Poseidon/core/application/Layer.h"

namespace poseidon
{
    class RenderLayer : public Layer
    {
    public:
        explicit RenderLayer(std::string name);

        auto onAttach(Application &app) -> void override;
        auto onUpdate(std::chrono::milliseconds timeDelta) -> void override;
        auto onDetach() -> void override;

        virtual auto onRender(std::chrono::microseconds timeDelta) -> void = 0;
    };
}
