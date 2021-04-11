#pragma once

#include "Poseidon/rendering/data/VertexBuffer.h"

#include <glbinding/gl/gl.h>

namespace poseidon
{
    class OpenGLVertexBuffer : public VertexBuffer
    {
    public:
        explicit OpenGLVertexBuffer();

        [[nodiscard]] gl::GLuint getId() const;

    private:
        void setData(void *data, std::size_t size, VertexBufferMode mode) override;
        void *map() override;
        void unmap() override;

        static gl::GLenum vertexBufferModeToGlMode(VertexBufferMode mode);

    private:
        gl::GLuint m_bufferId = 0;
    };
}
