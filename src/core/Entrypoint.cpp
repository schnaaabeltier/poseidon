#include "poseidon/core/Application.h"
#include "poseidon/core/Entrypoint.h"

#include <memory>

int main(int argc, char **argv) {
    auto app = std::unique_ptr<poseidon::Application>(poseidon::createApplication(argc, argv));
    app->run();
}
