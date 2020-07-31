#pragma once

#include "Poseidon/core/events/EventHandler.h"

#include <any>
#include <concepts>
#include <string>

namespace poseidon {
    class Event {
    public:
        explicit Event(std::any data);
        virtual ~Event() = default;

        virtual void dispatch(EventHandler* handler) = 0;

        template<typename T>
        T getData() const {
            return std::any_cast<T>(m_data);
        };

    protected:
        [[nodiscard]] const std::any& getGenericData() const;

    private:
        std::any m_data;
    };

    template <typename T>
    concept IsEvent = std::is_base_of<Event, T>::value;
}