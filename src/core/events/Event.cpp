#include "Poseidon/core/events/Event.h"

#include <utility>

poseidon::Event::Event(std::string type, std::any data) : m_type(std::move(type)), m_data(std::move(data)) {

}

const std::any& poseidon::Event::getGenericData() const {
    return m_data;
}

const std::string &poseidon::Event::getType() const {
    return m_type;
}
