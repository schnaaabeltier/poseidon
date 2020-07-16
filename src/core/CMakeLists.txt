set(target core)

set(sources
        ${headers}

        Application.cpp
        Entrypoint.cpp

        logging/Logger.cpp
        logging/SpdConsoleLogger.cpp)


add_library(${target} ${sources})
target_include_directories(${target} PRIVATE
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>)

target_link_libraries(${target} glfw spdlog::spdlog)