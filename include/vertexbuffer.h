#pragma once
#define GL_GLEXT_PROTOTYPES
#define EGL_EGLEXT_PROTOTYPES
#include <GL/gl.h>
#include <GLFW/glfw3.h>

class VertexBuffer
{
public:
    VertexBuffer(const void* p_data, unsigned int size);
    ~VertexBuffer();

    void bind();
    void unbind();

private:
    unsigned int _bufferId;
};
