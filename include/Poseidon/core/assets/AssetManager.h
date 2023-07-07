#pragma once

#include <filesystem>

namespace poseidon
{
    class AssetManager
    {
    public:
        explicit AssetManager(std::filesystem::path assetsBasePath);

        std::filesystem::path getAssetPath(std::filesystem::path assetRelativePath);

    private:
        std::filesystem::path m_assetsBasePath;
    };
}