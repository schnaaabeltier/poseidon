#include "Poseidon/core/Application.h"
#include "Poseidon/core/Entrypoint.h"

#include <memory>

int main(int argc, char **argv) {
    auto app = std::unique_ptr<poseidon::Application>(poseidon::createApplication(argc, argv));
    app->run();
}
