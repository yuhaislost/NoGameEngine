#include "graphics/buffers/buffer.hpp"

namespace NoGameEngine
{
    namespace Graphics
    {
        Buffer::Buffer(GLfloat* t_Data, GLsizei t_Count, GLuint t_ComponentCount) : m_ComponentCount(t_ComponentCount)
        {
            glGenBuffers(1, &m_BufferID);
            glBindBuffer(GL_ARRAY_BUFFER, m_BufferID);
            glBufferData(GL_ARRAY_BUFFER, t_Count * sizeof(GLfloat), t_Data, GL_STATIC_DRAW);
            glBindBuffer(GL_ARRAY_BUFFER, 0);
        }

        Buffer::~Buffer()
        {
            glDeleteBuffers(1, &m_BufferID);
        }

        void Buffer::bind() const
        {
            glBindBuffer(GL_ARRAY_BUFFER, m_BufferID);
        }

        void Buffer::unbind() const
        {
            glBindBuffer(GL_ARRAY_BUFFER, 0);
        }
    }
}