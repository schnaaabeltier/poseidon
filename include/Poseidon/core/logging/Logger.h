#pragma once

#include <memory>
#include <string>

namespace poseidon {
    enum LogChannel {
        INFO,
        DEBUG,
        WARNING,
        ERROR
    };

    class Logger {
    public:
        virtual ~Logger() = default;

        virtual void info(const std::string &message) = 0;
        virtual void debug(const std::string &message) = 0;
        virtual void warning(const std::string &message) = 0;
        virtual void error(const std::string &message) = 0;

        static void initialize();

        static void setClientLogger(Logger *logger);
        static void setCoreLogger(Logger *logger);

        static const Logger &getClientLogger();
        static const Logger &getCoreLogger();

    private:
        static std::unique_ptr<Logger> m_coreLogger;
        static std::unique_ptr<Logger> m_clientLogger;
    };

    extern Logger *createClientLogger();
    extern Logger *createCoreLogger();
}

#define PS_CORE_INFO(...) poseidon::Logger::getClientLogger()->info(__VA_ARGS__)