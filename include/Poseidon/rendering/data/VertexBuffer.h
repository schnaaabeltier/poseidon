#pragma once

#include <cstddef>
#include <memory>

namespace poseidon
{
    enum VertexBufferMode
    {
        Static,
        Dynamic
    };

    class VertexBuffer
    {
    public:
        virtual ~VertexBuffer() = default;

        virtual void setData(void* data, std::size_t size, VertexBufferMode mode) = 0;
        virtual void* map() = 0;
        virtual void unmap() = 0;
    };

    class VertexBufferFactory
    {
    public:
        static std::unique_ptr<VertexBuffer> createVertexBuffer();
    };
}
