#pragma once

#include "Poseidon/core/logging/Logger.h"
#include "Poseidon/rendering/Shader.h"

#include <glbinding/gl/gl.h>

namespace poseidon {
    template<ShaderType Type>
    class OpenGLShader : public Shader<Type> {
    public:
        explicit OpenGLShader(const std::string& name) : Shader<Type>(name) {

        };

        ~OpenGLShader() override {
            gl::glDeleteShader(m_shaderId);
        }

        auto load(std::string source) -> void override {
            m_shaderId = gl::glCreateShader(convertShaderType<Type>());

            auto shaderSource = source.c_str();

            gl::glShaderSource(m_shaderId, 1, &shaderSource, nullptr);
        };

        auto compile() -> void override {
            gl::glCompileShader(m_shaderId);

            int success;
            gl::glGetShaderiv(m_shaderId, gl::GL_COMPILE_STATUS, &success);
            if (!success) {
                auto errorBuffer = std::array<char, 1024>();
                gl::glGetShaderInfoLog(m_shaderId, 1024, nullptr, errorBuffer.data());
                PS_CORE_ERROR("Failed to compile shader: {}", std::string(errorBuffer.data()));
            }
        };

        auto getHandle() -> std::any override {
            return m_shaderId;
        }

        auto use() -> void override {

        }

        template<ShaderType PoseidonShaderType>
        static auto convertShaderType() -> gl::GLenum {
            switch(PoseidonShaderType) {
                case ShaderType::Vertex:
                    return gl::GL_VERTEX_SHADER;
                case ShaderType::Fragment:
                    return gl::GL_FRAGMENT_SHADER;
                case ShaderType::Compute:
                    return gl::GL_COMPUTE_SHADER;
            }
        };

    private:
        gl::GLuint m_shaderId = 0;
    };

    using OpenGLVertexShader = OpenGLShader<ShaderType::Vertex>;
    using OpenGLFragmentShader = OpenGLShader<ShaderType::Fragment>;
    using OpenGLComputeShader = OpenGLShader<ShaderType::Compute>;
}