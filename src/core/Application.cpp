#include "Poseidon/core/Application.h"
#include "Poseidon/core/logging/Logger.h"

void poseidon::Application::start() {
    poseidon::Logger::initialize();

    run();
}