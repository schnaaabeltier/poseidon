#pragma once

#include "Poseidon/core/logging/Logger.h"

#include <spdlog/spdlog.h>

namespace poseidon {
    class SpdConsoleLogger : public Logger {
    public:
        SpdConsoleLogger(const std::string &name);
        ~SpdConsoleLogger() override;

        void info(const std::string &message) override;
        void debug(const std::string &message) override;
        void warning(const std::string &message) override;
        void error(const std::string &message) override;

    private:
        std::shared_ptr<spdlog::logger> m_logger;
    };
}