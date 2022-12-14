#pragma once
#define GL_GLEXT_PROTOTYPES
#define EGL_EGLEXT_PROTOTYPES
#include <GL/gl.h>
#include <GLFW/glfw3.h>
#include "vertexbuffer.h"
#include "vertexbufferlayout.h"

class VertexArray
{
public:
    VertexArray();
    ~VertexArray();

    void addBuffer(VertexBuffer& p_vertexBuffer, const VertexBufferLayout& p_layout);

    void bind();
    void unbind();

    // TODO : shouldn't need this in future. Just keeping it now for testing
    inline unsigned int getId() const { return _arrayId; }
private:
    unsigned int _arrayId;
};
