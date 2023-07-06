set(OPTION_BUILD_EXAMPLES Off)
set(OPTION_BUILD_TOOLS Off)
set(OPTION_SELF_CONTAINED On)
add_subdirectory(glbinding)
if (WIN32)
    add_custom_command(TARGET glbinding POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:glbinding> ${PROJECT_BINARY_DIR}/glbinding.dll
            )
endif ()


set(GLFW_BUILD_DOCS Off)
set(GLFW_BUILD_EXAMPLES Off)
set(GLFW_BUILD_TESTS Off)
add_subdirectory(glfw)

set(CMAKE_POSITION_INDEPENDENT_CODE On)
add_subdirectory(spdlog)

file(GLOB imgui_sources
        imgui/*.cpp imgui/*.h)
add_library(imgui ${imgui_sources})
target_include_directories(imgui PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/imgui>
        $<INSTALL_INTERFACE:includeimgui>)