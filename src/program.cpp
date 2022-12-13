#include <iostream>
#include "program.h"

Program *Program::currentProgram = nullptr;

// TOOD: use ref p_shaders
Program::Program(std::vector<Shader *> shaders)
{
    programId = glCreateProgram();

    for(std::vector<Shader *>::iterator shader = shaders.begin(); shader != shaders.end(); shader++)
    {
        glAttachShader(programId, (*shader)->shaderId);
    }

    glLinkProgram(programId);

    GLint status;
    glGetProgramiv(programId, GL_LINK_STATUS, &status);
    if(status != GL_TRUE)
    {
        GLint logLen;
        glGetProgramiv(programId, GL_INFO_LOG_LENGTH, &logLen);
        GLchar *log = new GLchar[logLen + 1];
        glGetProgramInfoLog(programId, logLen + 1, nullptr, log);
        std::cerr << "ERROR : Unable to link program : " << std::to_string(programId) << " - " << std::string(log) << std::endl;
        return;
    }

    // No longer need for the shaders code as they've been linked into the program
    for(std::vector<Shader *>::iterator shader = shaders.begin(); shader != shaders.end(); shader++)
    {
        glDetachShader(programId, (*shader)->shaderId);
        glDeleteShader((*shader)->shaderId);
    }
}

Program::~Program()
{
    glDeleteProgram(programId);
}

GLuint Program::bind()
{
    currentProgram = this;
    glUseProgram(programId);
    return programId;
}

GLuint Program::unbind()
{
    currentProgram = nullptr;
    glUseProgram(0);
    return 0;
}
