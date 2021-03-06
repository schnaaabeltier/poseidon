#pragma once

#include <memory>
#include <string>

#include <spdlog/spdlog.h>

namespace poseidon {
    class Logger {
    public:
        virtual ~Logger() = default;

        static void initialize();

        static void setClientLogger(std::shared_ptr<spdlog::logger> logger);
        static void setCoreLogger(std::shared_ptr<spdlog::logger> logger);

        static std::shared_ptr<spdlog::logger> getClientLogger();
        static std::shared_ptr<spdlog::logger> getCoreLogger();

    private:
        static std::shared_ptr<spdlog::logger> m_coreLogger;
        static std::shared_ptr<spdlog::logger> m_clientLogger;
    };

    extern std::shared_ptr<spdlog::logger> createClientLogger();
    extern std::shared_ptr<spdlog::logger> createCoreLogger();
}

#define PS_CORE_INFO(...) poseidon::Logger::getCoreLogger()->info(__VA_ARGS__)
#define PS_CORE_DEBUG(...) poseidon::Logger::getCoreLogger()->debug(__VA_ARGS__)
#define PS_CORE_WARN(...) poseidon::Logger::getCoreLogger()->warn(__VA_ARGS__)
#define PS_CORE_ERROR(...) poseidon::Logger::getCoreLogger()->error(__VA_ARGS__)

#define PS_APP_INFO(...) poseidon::Logger::getClientLogger()->info(__VA_ARGS__)
#define PS_APP_DEBUG(...) poseidon::Logger::getClientLogger()->debug(__VA_ARGS__)
#define PS_APP_WARN(...) poseidon::Logger::getClientLogger()->warn(__VA_ARGS__)
#define PS_APP_ERROR(...) poseidon::Logger::getClientLogger()->error(__VA_ARGS__)
