#pragma once

namespace poseidon {
    class Application {
    public:
        void start();

        virtual void run() = 0;
    };

    extern Application *createApplication(int argc, char **argv);
}
