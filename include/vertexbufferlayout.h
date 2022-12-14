#pragma once

#include<vector>
#define GL_GLEXT_PROTOTYPES
#define EGL_EGLEXT_PROTOTYPES
#include <GL/gl.h>
#include <GLFW/glfw3.h>

struct VertexBufferLayoutElement
{
    unsigned int type;
    unsigned int count;
    unsigned int normalised;

    static unsigned int getSizeOfType(unsigned int type)
    {
        // TODO: uh... can't we just return sizeof(type)? Need to check why it's done this way...
        switch(type)
        {
            case GL_FLOAT : return 4;
            case GL_UNSIGNED_INT : return 4;
            case GL_UNSIGNED_BYTE: return 1;
        }
        return 0;
    }
};

class VertexBufferLayout
{
public:
    VertexBufferLayout()
        :_stride(0) {}
    
    template<typename T>
    void push(unsigned int count){}

    template<>
    void push<float>(unsigned int count)
    {
        _elements.push_back({GL_FLOAT, count, GL_FALSE});
        _stride += VertexBufferLayoutElement::getSizeOfType(GL_FLOAT) * count;        
    }

    template<>
    void push<unsigned int>(unsigned int count)
    {
        _elements.push_back({GL_UNSIGNED_INT, count, GL_FALSE});
        _stride += VertexBufferLayoutElement::getSizeOfType(GL_UNSIGNED_INT) * count;        
    }

    template<>
    void push<unsigned char>(unsigned int count)
    {
        _elements.push_back({GL_UNSIGNED_BYTE, count, GL_FALSE});
        _stride += VertexBufferLayoutElement::getSizeOfType(GL_UNSIGNED_BYTE) * count;        
    }

    inline const std::vector<VertexBufferLayoutElement> getElements() const { return _elements; }
    inline unsigned int getStride() const { return _stride; }
private:
    unsigned int _stride;
    std::vector<VertexBufferLayoutElement> _elements;
};
