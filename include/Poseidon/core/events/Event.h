#pragma once

#include "Poseidon/core/events/EventHandler.h"

#include <any>
#include <string>

namespace poseidon {
    class Event {
    public:
        Event(std::string type, std::any data);
        virtual ~Event() = default;

        template<typename T>
        const T& getData() const {
            return std::any_cast<T>(getGenericData());
        };

        [[nodiscard]] const std::string &getType() const;

    protected:
        [[nodiscard]] const std::any& getGenericData() const;

    private:
        std::string m_type;
        std::any m_data;
    };
}