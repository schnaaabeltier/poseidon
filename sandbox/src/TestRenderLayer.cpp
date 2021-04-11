#include "TestRenderLayer.h"

#include "Poseidon/core/logging/Logger.h"

#include "Poseidon/rendering/ShaderFactory.h"
#include "Poseidon/rendering/data/VertexBuffer.h"
#include "Poseidon/rendering/platform/opengl/OpenGLVertexBuffer.h"

#include "glbinding/gl/gl.h"

using namespace poseidon;

TestRenderLayer::TestRenderLayer() : poseidon::RenderLayer("TestRenderLayer") {

}

void TestRenderLayer::onRender(std::chrono::microseconds timeDelta) {
    float vertices[] = {
            -0.5f, -0.5f, 0.0f,
            0.5f, -0.5f, 0.0f,
            0.0f,  0.5f, 0.0f
    };

    auto vertexBuffer = VertexBufferFactory::createVertexBuffer();
    vertexBuffer->setData(vertices, sizeof(vertices), Static);

    unsigned int vertexArray;
    gl::glGenVertexArrays(1, &vertexArray);
    gl::glBindVertexArray(vertexArray);

    gl::glVertexAttribPointer(0, 3, gl::GL_FLOAT, gl::GL_FALSE, 3 * sizeof(float), (void*)0);
    gl::glEnableVertexAttribArray(0);

    auto shaderPath = "/home/jakob/projects/poseidon/sandbox/assets/test.vert";
    auto vertexShader = poseidon::ShaderFactory::createShader<poseidon::ShaderType::Vertex>("VertexShader", shaderPath);
    vertexShader->compile();

    auto fragmentShaderPath = "/home/jakob/projects/poseidon/sandbox/assets/test.vert";
    auto fragmentShader = poseidon::ShaderFactory::createShader<poseidon::ShaderType::Fragment>("FragmentShader", fragmentShaderPath);
    fragmentShader->compile();

    auto shaderProgram = poseidon::ShaderFactory::createShaderProgram();
    shaderProgram->setVertexShader(vertexShader);
    shaderProgram->setFragmentShader(fragmentShader);
    shaderProgram->link();
    shaderProgram->use();

    gl::glDrawArrays(gl::GLenum::GL_TRIANGLES, 0, 3);
}
