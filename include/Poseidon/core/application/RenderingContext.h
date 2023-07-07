#include <chrono>
#include "Poseidon/core/assets/AssetManager.h"

namespace poseidon
{
    struct RenderingContext
    {
        std::chrono::milliseconds timeDelta;
        AssetManager& assetManager;
    };
}
