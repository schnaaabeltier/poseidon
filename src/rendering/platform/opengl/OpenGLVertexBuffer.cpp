#include "Poseidon/rendering/platform/opengl/OpenGLVertexBuffer.h"

poseidon::OpenGLVertexBuffer::OpenGLVertexBuffer()
{
    gl::glCreateBuffers(1, &m_bufferId);
}

void poseidon::OpenGLVertexBuffer::setData(void *data, std::size_t size, poseidon::VertexBufferMode mode)
{
    gl::glNamedBufferData(m_bufferId, size, data, vertexBufferModeToGlMode(mode));
}

void *poseidon::OpenGLVertexBuffer::map()
{
    return gl::glMapNamedBuffer(m_bufferId, gl::GLenum::GL_READ_WRITE);
}

void poseidon::OpenGLVertexBuffer::unmap()
{
    gl::glUnmapNamedBuffer(m_bufferId);
}

gl::GLuint poseidon::OpenGLVertexBuffer::getId() const
{
    return m_bufferId;
}

auto poseidon::OpenGLVertexBuffer::bind() -> void
{
    gl::glBindBuffer(gl::GLenum::GL_ARRAY_BUFFER, m_bufferId);
}

gl::GLenum poseidon::OpenGLVertexBuffer::vertexBufferModeToGlMode(VertexBufferMode mode)
{
    switch (mode)
    {
        case VertexBufferMode::Static:
            return gl::GL_STATIC_DRAW;
        case VertexBufferMode::Dynamic:
            return gl::GL_DYNAMIC_DRAW;
    }
    return gl::GL_STATIC_DRAW;
}
