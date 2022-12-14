#include "indexbuffer.h"

IndexBuffer::IndexBuffer(const void* p_data, unsigned int count)
{
    glGenBuffers(1, &_bufferId);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _bufferId);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), p_data, GL_STATIC_DRAW);
}

IndexBuffer::~IndexBuffer()
{
    glDeleteBuffers(1, &_bufferId);
}

void IndexBuffer::bind()
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _bufferId);
}

void IndexBuffer::unbind()
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}
