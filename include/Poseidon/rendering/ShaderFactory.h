#pragma once

#include "RenderingApi.h"
#include "Shader.h"
#include "ShaderProgram.h"

#include "platform/opengl/OpenGLShader.h"
#include "platform/opengl/OpenGLShaderProgram.h"

namespace poseidon {
    class ShaderFactory {
    public:
        template<ShaderType Type>
        static auto createShader(const std::string& name, const std::filesystem::path& shaderPath) -> std::shared_ptr<Shader<Type>> {
            if (RenderingApi::current() == RenderingPlatform::OpenGL) {
                std::string shaderSource = Shader<Type>::readSourceFromFile(shaderPath);
                auto shader = std::make_shared<OpenGLShader<Type>>(name);
                shader->load(shaderSource);
                return shader;
            }
            else {
                return nullptr;
            }
        }

        static auto createShaderProgram() -> std::shared_ptr<ShaderProgram> {
            if (RenderingApi::current() == RenderingPlatform::OpenGL) {
                return std::make_shared<OpenGLShaderProgram>();
            }
            else {
                return nullptr;
            }
        }
    };
}