#pragma once

#define IMGUI_IMPL_OPENGL_LOADER_GLBINDING3
#define GLFW_INCLUDE_NONE       // GLFW including OpenGL headers causes ambiguity or multiple definition errors.
#include <glbinding/glbinding.h>
#include <glbinding/gl/gl.h>
using namespace gl;

#include "ImGuiImplGLFW.h"
#include "ImGuiImplOpenGL3.h"