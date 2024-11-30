#pragma once
#include <vector>
#include <GL/glew.h>

#include "buffer.hpp"

namespace NoGameEngine
{
    namespace Graphics
    {
        class VertexArray
        {
            public:
                VertexArray();
                ~VertexArray();

                void addBuffer(Buffer* t_Buffer, GLuint t_Index);
                void bind() const;
                void unbind() const;

            private:
                GLuint m_ArrayID;
                std::vector<Buffer *> m_Buffers;
        };
    }
}