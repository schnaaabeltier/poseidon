#include "Poseidon/core/logging/Logger.h"

void poseidon::Logger::initialize() {
    setClientLogger(createClientLogger());
    setCoreLogger(createCoreLogger());
}

void poseidon::Logger::setClientLogger(Logger *logger) {
    m_clientLogger = std::unique_ptr<Logger>(logger);
}

void poseidon::Logger::setCoreLogger(Logger *logger) {
    m_coreLogger = std::unique_ptr<Logger>(logger);
}

const poseidon::Logger& poseidon::Logger::getClientLogger() {
    return *m_clientLogger;
}

const poseidon::Logger& poseidon::Logger::getCoreLogger() {
    return *m_coreLogger;
}
