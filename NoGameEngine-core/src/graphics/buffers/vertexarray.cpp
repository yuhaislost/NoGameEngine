#include "graphics/buffers/vertexarray.hpp"

namespace NoGameEngine
{
    namespace Graphics
    {
        VertexArray::VertexArray()
        {
            glGenVertexArrays(1, &m_ArrayID);
        }

        VertexArray::~VertexArray()
        {
            for (int i {0}; i < m_Buffers.size(); i++)
                delete m_Buffers[i];

            glDeleteVertexArrays(1, &m_ArrayID);
        }

        void VertexArray::addBuffer(Buffer* t_Buffer, GLuint t_Index)
        {
            bind();
            t_Buffer->bind();
            glEnableVertexAttribArray(t_Index);
            glVertexAttribPointer(t_Index, t_Buffer->getComponentCount(), GL_FLOAT, GL_FALSE, 0, 0);

            t_Buffer->unbind();
            unbind();
        }

        void VertexArray::bind() const
        {
            glBindVertexArray(m_ArrayID);
        }

        void VertexArray::unbind() const
        {
            glBindVertexArray(0);
        }
    }
}