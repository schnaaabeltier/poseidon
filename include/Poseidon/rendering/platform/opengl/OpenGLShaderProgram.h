#pragma once

#include "Poseidon/rendering/ShaderProgram.h"

#include <glbinding/gl/gl.h>

namespace poseidon {
    class OpenGLShaderProgram : public ShaderProgram {
    public:
        OpenGLShaderProgram();

        auto link() -> void override;
        auto getHandle() -> std::any override;

    private:
        gl::GLuint m_programId = 0;
    };
}