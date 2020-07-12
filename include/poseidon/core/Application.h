#pragma once

namespace poseidon {
    class Application {
    public:
        virtual void run() = 0;
    };

    extern Application *createApplication(int argc, char **argv);
}
