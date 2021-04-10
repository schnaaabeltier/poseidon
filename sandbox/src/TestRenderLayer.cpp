#include "TestRenderLayer.h"

#include "Poseidon/core/logging/Logger.h"

#include "Poseidon/rendering/platform/opengl/OpenGLShaderProgram.h"
#include "Poseidon/rendering/ShaderFactory.h"

#include "glbinding/gl/gl.h"

TestRenderLayer::TestRenderLayer() : poseidon::RenderLayer("TestRenderLayer") {

}

void TestRenderLayer::onRender(std::chrono::microseconds timeDelta) {
    float vertices[] = {
            -0.5f, -0.5f, 0.0f,
            0.5f, -0.5f, 0.0f,
            0.0f,  0.5f, 0.0f
    };

    unsigned int vertexArray;
    gl::glGenVertexArrays(1, &vertexArray);
    gl::glBindVertexArray(vertexArray);

    unsigned int vertexBuffer;
    gl::glGenBuffers(1, &vertexBuffer);
    gl::glBindBuffer(gl::GLenum::GL_ARRAY_BUFFER, vertexBuffer);
    gl::glBufferData(gl::GLenum::GL_ARRAY_BUFFER, sizeof(vertices), vertices, gl::GLenum::GL_STATIC_DRAW);
    gl::glVertexAttribPointer(0, 3, gl::GL_FLOAT, gl::GL_FALSE, 3 * sizeof(float), (void*)0);
    gl::glEnableVertexAttribArray(0);

    auto shaderPath = "/home/jakob/projects/poseidon/sandbox/assets/test.vert";
    auto vertexShader = poseidon::ShaderFactory::createShader<poseidon::ShaderType::Vertex>("VertexShader", shaderPath);
    vertexShader->compile();

    auto fragmentShaderPath = "/home/jakob/projects/poseidon/sandbox/assets/test.vert";
    auto fragmentShader = poseidon::ShaderFactory::createShader<poseidon::ShaderType::Fragment>("FragmentShader", fragmentShaderPath);
    fragmentShader->compile();

    auto shaderProgram = poseidon::OpenGLShaderProgram();
    shaderProgram.setVertexShader(vertexShader);
    shaderProgram.setFragmentShader(fragmentShader);
    shaderProgram.link();
    shaderProgram.use();

    gl::glDrawArrays(gl::GLenum::GL_TRIANGLES, 0, 3);
}
