#include "Poseidon/rendering/platform/opengl/OpenGLShaderProgram.h"

#include "Poseidon/core/logging/Logger.h"

poseidon::OpenGLShaderProgram::OpenGLShaderProgram() {

}

auto poseidon::OpenGLShaderProgram::link() -> void {
    auto vertexShader = getVertexShader();
    auto fragmentShader = getFragmentShader();
    auto computeShader = getComputeShader();

    if (vertexShader) {
        auto vertexShaderId = std::any_cast<gl::GLuint>(vertexShader->getHandle());
        gl::glAttachShader(m_programId, vertexShaderId);
    }

    if (fragmentShader) {
        auto fragmentShaderId = std::any_cast<gl::GLuint>(fragmentShader->getHandle());
        gl::glAttachShader(m_programId, fragmentShaderId);
    }

    if (computeShader) {
        auto computeShaderId = std::any_cast<gl::GLuint>(computeShader->getHandle());
        gl::glAttachShader(m_programId, computeShaderId);
    }

    gl::glLinkProgram(m_programId);

    int success;
    gl::glGetProgramiv(m_programId, gl::GLenum::GL_LINK_STATUS, &success);
    if (!success) {
        auto errorData = std::array<char, 1024>();
        gl::glGetProgramInfoLog(m_programId, 1024, nullptr, errorData.data());
        PS_CORE_ERROR("Error when linking shader program: {}", std::string(errorData.data()));
    }
}

std::any poseidon::OpenGLShaderProgram::getHandle() {
    return m_programId;
}

auto poseidon::OpenGLShaderProgram::use() -> void {
    gl::glUseProgram(m_programId);
}