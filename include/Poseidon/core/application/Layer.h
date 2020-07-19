#pragma once

#include <chrono>
#include <string>

namespace poseidon {
    class Layer {
    public:
        Layer(std::string name);

        virtual void onUpdate(std::chrono::milliseconds timeDelta) = 0;

    private:
        std::string m_name;
    };
}