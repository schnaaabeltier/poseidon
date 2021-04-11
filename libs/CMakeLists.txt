set(OPTION_BUILD_EXAMPLES Off)
set(OPTION_BUILD_TOOLS Off)
set(OPTION_SELF_CONTAINED On)
add_subdirectory(glbinding)

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