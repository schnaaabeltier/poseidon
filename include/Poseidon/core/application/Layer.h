#pragma once

#include <chrono>
#include <string>

namespace poseidon {
    class Application;

    class Layer {
    public:
        explicit Layer(std::string name);
        virtual ~Layer() = default;

        virtual void onAttach(Application& app) = 0;
        virtual void onUpdate(std::chrono::milliseconds timeDelta) = 0;
        virtual void onDetach() = 0;

    private:
        std::string m_name;
    };
}