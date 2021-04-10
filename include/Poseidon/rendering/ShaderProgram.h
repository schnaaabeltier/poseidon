#pragma once

#include "Shader.h"

#include <any>
#include <memory>

namespace poseidon {
    class ShaderProgram {
    public:
        auto setFragmentShader(std::shared_ptr<Shader<ShaderType::Fragment>> shader) -> void;
        auto setVertexShader(std::shared_ptr<Shader<ShaderType::Vertex>> shader) -> void;
        auto setComputeShader(std::shared_ptr<Shader<ShaderType::Compute>> shader) -> void;

        auto getVertexShader() -> std::shared_ptr<Shader<ShaderType::Vertex>>;
        auto getFragmentShader() -> std::shared_ptr<Shader<ShaderType::Fragment>>;
        auto getComputeShader() -> std::shared_ptr<Shader<ShaderType::Compute>>;

        virtual auto use() -> void = 0;
        virtual auto link() -> void = 0;
        virtual auto getHandle() -> std::any = 0;

    private:
        std::shared_ptr<Shader<ShaderType::Vertex>> m_vertexShader;
        std::shared_ptr<Shader<ShaderType::Fragment>> m_fragmentShader;
        std::shared_ptr<Shader<ShaderType::Compute>> m_computeShader;
    };
}