#pragma once

namespace poseidon {
    enum class RenderingPlatform {
        OpenGL,
        Vulkan
    };

    class RenderingApi {
    public:
        static auto current() -> RenderingPlatform {
            return RenderingPlatform::OpenGL;
        }
    };
}