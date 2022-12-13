#pragma once
#include <vector>
#include "shader.h"

class Program 
{
public:
    Program(std::vector<Shader *> shaders);
    ~Program();

    GLuint programId;
    static Program *currentProgram;

    GLuint bind();
    GLuint unbind();
private:
};
