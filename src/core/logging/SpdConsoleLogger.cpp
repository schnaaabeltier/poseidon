#include "Poseidon/core/logging/SpdConsoleLogger.h"

poseidon::SpdConsoleLogger::SpdConsoleLogger(const std::string &name) {
    m_logger = std::make_shared<spdlog::logger>(name);
    m_logger->set_pattern("[%H:%M:%S %z] [%n] [%^---%L---%$] [thread %t] %v");
    spdlog::register_logger(m_logger);
}

poseidon::SpdConsoleLogger::~SpdConsoleLogger() {

}

void poseidon::SpdConsoleLogger::info(const std::string &message) {
    m_logger->info(message);
}

void poseidon::SpdConsoleLogger::debug(const std::string &message) {
    m_logger->debug(message);
}

void poseidon::SpdConsoleLogger::warning(const std::string &message) {
    m_logger->warn(message);
}

void poseidon::SpdConsoleLogger::error(const std::string &message) {
    m_logger->error(message);
}
