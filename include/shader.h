#pragma once
#include <string>
#define GL_GLEXT_PROTOTYPES
#define EGL_EGLEXT_PROTOTYPES
#include <GL/gl.h>
#include <GLFW/glfw3.h>

class Shader
{
public:
    Shader(const std::string& p_filename, GLenum shaderType);
    ~Shader();

    GLuint shaderId;

private:
    GLenum _shaderType;
    std::string _shaderCode;

    std::string loadGlslFile(const std::string &p_filename);
};
