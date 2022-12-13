#include <iostream>
#include <fstream>
#include <sstream>
#include "shader.h"

Shader::Shader(const std::string& p_filename, GLenum shaderType)
    : _shaderType(shaderType)
{
    std::cout << "Loading shader : " << p_filename << std::endl;
    _shaderCode = loadGlslFile(p_filename);
    shaderId = glCreateShader(shaderType);

    const GLchar *shaderString = _shaderCode.c_str();
    glShaderSource(shaderId, 1, &shaderString, nullptr);
    glCompileShader(shaderId);

    GLint status;
    glGetShaderiv(shaderId, GL_COMPILE_STATUS, &status);
    if(status != GL_TRUE)
    {
        GLint logLen;
        glGetShaderiv(shaderId, GL_INFO_LOG_LENGTH, &logLen);
        GLchar *log = new GLchar[logLen + 1];
        glGetShaderInfoLog(shaderId, logLen + 1, nullptr, log);
        std::cerr << "ERROR : Unable to compile shader : " << p_filename << " - " << std::string(log) << std::endl;
        return;
    }

}

Shader::~Shader()
{
    glDeleteShader(shaderId);
}

std::string Shader::loadGlslFile(const std::string& p_filename)
{
    std::ifstream file(p_filename, std::ios::in | std::ios::binary);
    if(!file)
    {
        std::cerr << "ERROR : unable to load shader file : " << p_filename << std::endl;
        // TODO: proper error handling!
        return "";
    }

    std::ostringstream contents;
    contents << file.rdbuf();
    file.close();

    std::string contentsStr = contents.str();
    return contentsStr;
}
