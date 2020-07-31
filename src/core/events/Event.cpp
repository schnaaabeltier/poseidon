#include "Poseidon/core/events/Event.h"

#include <utility>

poseidon::Event::Event(std::any data) : m_data(std::move(data)) {

}

const std::any& poseidon::Event::getGenericData() const {
    return m_data;
}