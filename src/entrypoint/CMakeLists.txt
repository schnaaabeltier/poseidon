set(target entrypoint)

set(sources
        Entrypoint.cpp)


add_library(${target} STATIC ${sources})
target_compile_options(${target} PRIVATE ${default_compile_options})
target_include_directories(${target} PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>)

target_link_libraries(${target} core)
