#include "Poseidon/rendering/ShaderProgram.h"

#include <utility>

auto poseidon::ShaderProgram::getComputeShader() -> std::shared_ptr<Shader<ShaderType::Compute>> {
    return m_computeShader;
}

auto poseidon::ShaderProgram::setComputeShader(std::shared_ptr<Shader<ShaderType::Compute>> shader) -> void {
    m_computeShader = std::move(shader);
}

auto poseidon::ShaderProgram::getFragmentShader() -> std::shared_ptr<Shader<ShaderType::Fragment>> {
    return m_fragmentShader;
}

auto poseidon::ShaderProgram::setFragmentShader(std::shared_ptr<Shader<ShaderType::Fragment>> shader) -> void {
    m_fragmentShader = std::move(shader);
}

auto poseidon::ShaderProgram::getVertexShader() -> std::shared_ptr<Shader<ShaderType::Vertex>> {
    return m_vertexShader;
}

auto poseidon::ShaderProgram::setVertexShader(std::shared_ptr<Shader<ShaderType::Vertex>> shader) -> void {
    m_vertexShader = std::move(shader);
}