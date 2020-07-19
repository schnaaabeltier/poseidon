#include "Poseidon/core/application/Application.h"
#include "Poseidon/core/application/Entrypoint.h"
#include "Poseidon/core/logging/Logger.h"

#include <memory>

int main(int argc, char **argv) {
    poseidon::Logger::initialize();
    auto app = std::unique_ptr<poseidon::Application>(poseidon::createApplication(argc, argv));
    app->start();
}
