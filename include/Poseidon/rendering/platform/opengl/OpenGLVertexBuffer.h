#pragma once

#include "Poseidon/rendering/data/VertexBuffer.h"

#include <glbinding/gl/gl.h>

namespace poseidon
{
    class OpenGLVertexBuffer : public VertexBuffer
    {
    public:
        explicit OpenGLVertexBuffer();

        [[nodiscard]] auto getId() const -> gl::GLuint;

    private:
        auto setData(void *data, std::size_t size, VertexBufferMode mode) -> void override;
        auto map() -> void* override;
        auto unmap() -> void override;
        auto bind() -> void override;

        static gl::GLenum vertexBufferModeToGlMode(VertexBufferMode mode);

    private:
        gl::GLuint m_bufferId = 0;
    };
}
