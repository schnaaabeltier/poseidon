#pragma once

#include "RenderingApi.h"
#include "Shader.h"

#include "Poseidon/rendering/platform/opengl/OpenGLShader.h"

namespace poseidon {
    class ShaderFactory {
    public:
        template<ShaderType Type>
        static auto createShader(const std::filesystem::path& shaderPath) -> std::shared_ptr<Shader<Type>> {
            std::string shaderSource = Shader<Type>::readSourceFromFile(shaderPath);
            return std::make_shared<OpenGLShader<Type>>(shaderSource);
        }
    };
}