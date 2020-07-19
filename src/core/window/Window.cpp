#include "Poseidon/core/window/Window.h"

#include <utility>

poseidon::Window::Window(uint32_t width, uint32_t height, std::string title) : m_width(width), m_height(height), m_title(std::move(title)) {

}

uint32_t poseidon::Window::getWidth() const {
    return m_width;
}

void poseidon::Window::setWidth(uint32_t width) {
    m_width = width;
}

uint32_t poseidon::Window::getHeight() const {
    return m_height;
}

void poseidon::Window::setHeight(uint32_t height) {
    m_height = height;
}

const std::string &poseidon::Window::getTitle() const {
    return m_title;
}

void poseidon::Window::setTitle(const std::string &title) {
    m_title = title;
}

std::pair<uint32_t, uint32_t> poseidon::Window::getSize() const {
    return std::make_pair(m_width, m_height);
}
