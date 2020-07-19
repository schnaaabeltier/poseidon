#pragma once

#include <chrono>
#include <cstdint>
#include <string>
#include <utility>

namespace poseidon {
    class Window {
    public:
        Window(uint32_t width, uint32_t height, std::string title);
        virtual ~Window() = default;

        virtual void onUpdate(std::chrono::milliseconds timeDelta) = 0;

        [[nodiscard]] std::pair<uint32_t, uint32_t> getSize() const;

        [[nodiscard]] uint32_t getWidth() const;
        void setWidth(uint32_t width);

        [[nodiscard]] uint32_t getHeight() const;
        void setHeight(uint32_t height);

        [[nodiscard]] const std::string &getTitle() const;
        void setTitle(const std::string &title);

    private:
        uint32_t m_width { 1920 };
        uint32_t m_height { 1080 };
        std::string m_title;
    };
}