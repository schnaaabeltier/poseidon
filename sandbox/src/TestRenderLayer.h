#pragma once

#include "Poseidon/rendering/RenderLayer.h"

class TestRenderLayer : public poseidon::RenderLayer {
public:
    TestRenderLayer();

    auto onRender(poseidon::RenderingContext renderingContext) -> void override;
};
