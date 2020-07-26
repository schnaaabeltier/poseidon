set(target core)

set(sources
        ${headers}

        application/Application.cpp
        application/Entrypoint.cpp
        application/Layer.cpp

        events/Event.cpp
        events/EventDispatcher.cpp
        events/EventHandler.cpp
        events/EventQueue.cpp
        events/KeyEvent.cpp
        events/MouseEvent.cpp

        logging/Logger.cpp

        window/PoseidonGlfwWindow.cpp
        window/Window.cpp)


add_library(${target} ${sources})
target_compile_options(${target} PRIVATE ${default_compile_options})
target_include_directories(${target} PRIVATE
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>)

target_link_libraries(${target} glfw glbinding::glbinding spdlog::spdlog)