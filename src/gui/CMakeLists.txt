set(target gui)

set(sources
        ${headers}

        ImGuiLayer.cpp

        glfw/ImGuiImplGLFW.cpp
        glfw/ImGuiImplOpenGL3.cpp
        )


add_library(${target} ${sources})
target_compile_options(${target} PRIVATE ${default_compile_options})
target_include_directories(${target} PRIVATE
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>)

target_link_libraries(${target} core glfw glbinding::glbinding spdlog::spdlog imgui::imgui)