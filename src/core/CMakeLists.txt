set(target core)

set(sources
        ${headers}

        application/Application.cpp
        application/Layer.cpp

        events/Event.cpp
        events/EventDispatcher.cpp
        events/EventHandler.cpp
        events/EventQueue.cpp
        events/KeyEvents.cpp
        events/MouseEvents.cpp
        events/WindowEvents.cpp

        logging/Logger.cpp

        window/PoseidonGlfwWindow.cpp
        window/Window.cpp)


add_library(${target} SHARED ${sources})
target_compile_options(${target} PRIVATE ${default_compile_options})
target_include_directories(${target} PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>)

target_link_libraries(${target} PUBLIC glfw glbinding::glbinding spdlog::spdlog)
