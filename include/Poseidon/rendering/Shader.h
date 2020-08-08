#pragma once

#include "Poseidon/rendering/RenderingApi.h"

#include <any>
#include <filesystem>
#include <fstream>
#include <streambuf>

namespace poseidon {
    enum class ShaderType {
        Compute,
        Vertex,
        Fragment
    };

    template<ShaderType type>
    class Shader {
    public:
        explicit Shader(std::string name) : m_name(std::move(name)) {

        };

        virtual auto load(std::string source) -> void = 0;
        virtual auto compile() -> void = 0;
        virtual auto use() -> void = 0;
        virtual auto getHandle() -> std::any = 0;

        [[nodiscard]] auto getName() const noexcept -> std::string_view {
            return m_name;
        };

        static auto readSourceFromFile(const std::filesystem::path& shaderPath) -> std::string {
            std::ifstream stream(shaderPath.string());
            return std::string((std::istreambuf_iterator<char>(stream)), std::istreambuf_iterator<char>());
        }

    private:
        std::string m_name;
    };
}