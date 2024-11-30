#include "graphics/buffers/indexbuffer.hpp"

namespace NoGameEngine
{
    namespace Graphics
    {
        IndexBuffer::IndexBuffer(GLushort* t_Data, GLsizei t_Count) : m_Count(t_Count)
        {
            glGenBuffers(1, &m_BufferID);
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_BufferID);
            glBufferData(GL_ELEMENT_ARRAY_BUFFER, t_Count * sizeof(GLushort), t_Data, GL_STATIC_DRAW);
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
        }

        IndexBuffer::IndexBuffer(GLuint* t_Data, GLsizei t_Count) : m_Count(t_Count)
        {
            glGenBuffers(1, &m_BufferID);
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_BufferID);
            glBufferData(GL_ELEMENT_ARRAY_BUFFER, t_Count * sizeof(GLuint), t_Data, GL_STATIC_DRAW);
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
        }

        IndexBuffer::~IndexBuffer()
        {
            glDeleteBuffers(1, &m_BufferID);
        }

        void IndexBuffer::bind() const
        {
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_BufferID);
        }

        void IndexBuffer::unbind() const
        {
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
        }
    }
}