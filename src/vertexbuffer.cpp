#include "vertexbuffer.h"

VertexBuffer::VertexBuffer(const void* p_data, unsigned int size)
{
    glGenBuffers(1, &_bufferId);
    glBindBuffer(GL_ARRAY_BUFFER, _bufferId);
    glBufferData(GL_ARRAY_BUFFER, size, p_data, GL_STATIC_DRAW);
}

VertexBuffer::~VertexBuffer()
{
    glDeleteBuffers(1, &_bufferId);
}

void VertexBuffer::bind()
{
    glBindBuffer(GL_ARRAY_BUFFER, _bufferId);
}

void VertexBuffer::unbind()
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}
