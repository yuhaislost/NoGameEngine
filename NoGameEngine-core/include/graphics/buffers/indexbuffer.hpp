#pragma once
#include <GL/glew.h>

namespace NoGameEngine
{
    namespace Graphics
    {
        class IndexBuffer
        {
            public:

                IndexBuffer(GLushort* t_Data, GLsizei t_Count);
                IndexBuffer(GLuint* t_Data, GLsizei t_Count);
                ~IndexBuffer();
                void bind() const;
                void unbind() const;

                inline GLuint getCount() const { return m_Count; }

            private:

                GLuint m_BufferID;
                GLuint m_Count;
        };
    }
}