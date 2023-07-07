#include <utility>

#include "Poseidon/core/assets/AssetManager.h"

poseidon::AssetManager::AssetManager(std::filesystem::path assetsBasePath) : m_assetsBasePath(std::move(assetsBasePath))
{

}

std::filesystem::path poseidon::AssetManager::getAssetPath(std::filesystem::path assetRelativePath)
{
    return (m_assetsBasePath / assetRelativePath).make_preferred();
}
