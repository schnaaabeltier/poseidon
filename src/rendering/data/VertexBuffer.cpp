#include "Poseidon/rendering/data/VertexBuffer.h"
#include "Poseidon/rendering/platform/opengl/OpenGLVertexBuffer.h"
#include "Poseidon/rendering/RenderingApi.h"

std::unique_ptr<poseidon::VertexBuffer> poseidon::VertexBufferFactory::createVertexBuffer()
{
    if (RenderingApi::current() == RenderingPlatform::OpenGL)
    {
        return std::make_unique<OpenGLVertexBuffer>();
    }

    return nullptr;
}
