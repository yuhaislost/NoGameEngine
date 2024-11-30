#pragma once
#include <GL/glew.h>

namespace NoGameEngine
{
    namespace Graphics
    {
        class Buffer
        {
            public:

                Buffer(GLfloat* t_Data, GLsizei t_Count, GLuint t_ComponentCount);
                ~Buffer();
                void bind() const;
                void unbind() const;

                inline GLuint getComponentCount() const { return m_ComponentCount; }

            private:

                GLuint m_BufferID;
                GLuint m_ComponentCount;
        };
    }
}