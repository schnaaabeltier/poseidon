set(target ${library_name}_core)

set(sources
        core/Application.cpp
        core/Entrypoint.cpp)

add_library(${target} ${sources})
target_include_directories(${target} PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>)