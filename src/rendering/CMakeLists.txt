set(target rendering)

set(sources
        ${headers}

        data/VertexBuffer.cpp

        platform/opengl/OpenGLShaderProgram.cpp
        platform/opengl/OpenGLVertexBuffer.cpp

        RenderCommand.cpp
        RenderLayer.cpp
        ShaderProgram.cpp
        )

add_library(${target} SHARED ${sources})
target_compile_options(${target} PRIVATE ${default_compile_options})
target_include_directories(${target} PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>)

target_link_libraries(${target} PUBLIC core glbinding::glbinding)