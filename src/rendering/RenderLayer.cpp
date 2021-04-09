#include "Poseidon/rendering/RenderLayer.h"

poseidon::RenderLayer::RenderLayer(std::string name) : Layer(std::move(name)) {

}

auto poseidon::RenderLayer::onAttach(poseidon::Application &app) -> void {

}

auto poseidon::RenderLayer::onUpdate(std::chrono::milliseconds timeDelta) -> void {
    onRender(timeDelta);
}

auto poseidon::RenderLayer::onDetach() -> void {

}
