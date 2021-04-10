#include "Poseidon/core/logging/Logger.h"

#include <spdlog/sinks/stdout_color_sinks.h>

std::shared_ptr<spdlog::logger> poseidon::Logger::m_clientLogger = nullptr;
std::shared_ptr<spdlog::logger> poseidon::Logger::m_coreLogger = nullptr;

void poseidon::Logger::initialize() {
    spdlog::set_pattern("%^[%T][%-6l] %n : %v%$");
    m_coreLogger = spdlog::stdout_color_mt("Core");
    m_clientLogger = spdlog::stdout_color_mt("App");
    m_coreLogger->set_level(spdlog::level::debug);
    m_clientLogger->set_level(spdlog::level::debug);
}

void poseidon::Logger::setClientLogger(std::shared_ptr<spdlog::logger> logger) {
    m_clientLogger = std::move(logger);
}

void poseidon::Logger::setCoreLogger(std::shared_ptr<spdlog::logger> logger) {
    m_coreLogger = std::move(logger);
}

std::shared_ptr<spdlog::logger> poseidon::Logger::getClientLogger() {
    return m_clientLogger;
}

std::shared_ptr<spdlog::logger> poseidon::Logger::getCoreLogger() {
    return m_coreLogger;
}
