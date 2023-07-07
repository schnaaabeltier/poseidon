#include "TestRenderLayer.h"

#include "Poseidon/core/logging/Logger.h"

#include "Poseidon/rendering/ShaderFactory.h"
#include "Poseidon/rendering/data/VertexBuffer.h"
#include "Poseidon/rendering/platform/opengl/OpenGLVertexBuffer.h"

#include "glbinding/gl/gl.h"

using namespace poseidon;

TestRenderLayer::TestRenderLayer() : poseidon::RenderLayer("TestRenderLayer") {

}

void TestRenderLayer::onRender(poseidon::RenderingContext renderingContext) {
    float vertices[] = {
            -0.5f, -0.5f, 0.0f,
            0.5f, -0.5f, 0.0f,
            0.0f,  0.5f, 0.0f
    };

    PS_APP_INFO("Starting render process");

    auto vertexBuffer = VertexBufferFactory::createVertexBuffer();
    vertexBuffer->setData(vertices, sizeof(vertices), Static);
    vertexBuffer->bind();

    PS_APP_INFO("Created vertex buffer");

    unsigned int vertexArray;
    gl::glGenVertexArrays(1, &vertexArray);
    gl::glBindVertexArray(vertexArray);

    gl::glVertexAttribPointer(0, 3, gl::GL_FLOAT, gl::GL_FALSE, 3 * sizeof(float), (void*)0);
    gl::glEnableVertexAttribArray(0);

    PS_APP_INFO("Created vertex array");

    auto shaderPath = renderingContext.assetManager.getAssetPath("assets/test.vert");
    PS_APP_INFO("Loading vertex shader {}", shaderPath.string());
    auto vertexShader = poseidon::ShaderFactory::createShader<poseidon::ShaderType::Vertex>("VertexShader", shaderPath);
    vertexShader->compile();

    auto fragmentShaderPath = renderingContext.assetManager.getAssetPath("assets/test.frag");
    auto fragmentShader = poseidon::ShaderFactory::createShader<poseidon::ShaderType::Fragment>("FragmentShader", fragmentShaderPath);
    PS_APP_INFO("Loading fragment shader {}", fragmentShaderPath.string());
    fragmentShader->compile();

    auto shaderProgram = poseidon::ShaderFactory::createShaderProgram();
    shaderProgram->setVertexShader(vertexShader);
    shaderProgram->setFragmentShader(fragmentShader);
    shaderProgram->link();
    shaderProgram->use();
    PS_APP_INFO("Using shader program");

    gl::glDrawArrays(gl::GLenum::GL_TRIANGLES, 0, 3);
    PS_APP_INFO("Finished rendering");
}
