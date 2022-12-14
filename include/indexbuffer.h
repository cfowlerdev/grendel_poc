#pragma once
#define GL_GLEXT_PROTOTYPES
#define EGL_EGLEXT_PROTOTYPES
#include <GL/gl.h>
#include <GLFW/glfw3.h>

class IndexBuffer
{
public:
    IndexBuffer(const void* p_data, unsigned int count);
    ~IndexBuffer();

    void bind();
    void unbind();
    inline unsigned int getCount() const { return _count; }
private:
    unsigned int _bufferId;
    unsigned int _count;
};
