#pragma once

#include "RenderingApi.h"
#include "Shader.h"

#include "Poseidon/rendering/platform/opengl/OpenGLShader.h"

namespace poseidon {
    class ShaderFactory {
    public:
        template<ShaderType Type>
        static auto createShader(const std::string& name, const std::filesystem::path& shaderPath) -> std::shared_ptr<Shader<Type>> {
            std::string shaderSource = Shader<Type>::readSourceFromFile(shaderPath);
            auto shader = std::make_shared<OpenGLShader<Type>>(name);
            shader->load(shaderSource);
            return shader;
        }
    };
}