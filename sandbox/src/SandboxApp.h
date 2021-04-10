#pragma once

#include "Poseidon/Poseidon.h"

class SandboxApp : public poseidon::Application {
public:
    SandboxApp(const std::string& assetsBasePath);
};

