#include "graphics/batchrenderer2d.hpp"

namespace NoGameEngine
{
    namespace Graphics
    {
        BatchRenderer2D::BatchRenderer2D()
        {
            init();
        }
        
        BatchRenderer2D::~BatchRenderer2D()
        {
            delete m_IBO;
            glDeleteBuffers(1, &m_VBO);
        }

        void BatchRenderer2D::init()
        {
            glGenVertexArrays(1, &m_VAO);
            glGenBuffers(1, &m_VBO);

            glBindVertexArray(m_VAO);
            glBindBuffer(GL_ARRAY_BUFFER, m_VBO);

            glBufferData(GL_ARRAY_BUFFER, RENDERER_BUFFER_SIZE, NULL, GL_DYNAMIC_DRAW);
            glEnableVertexAttribArray(SHADER_VERTEX_INDEX);
            glEnableVertexAttribArray(SHADER_COLOUR_INDEX);
            glVertexAttribPointer(SHADER_VERTEX_INDEX, 3, GL_FLOAT, GL_FALSE, RENDERER_VERTEX_SIZE, (const GLvoid *)0);
            glVertexAttribPointer(SHADER_COLOUR_INDEX, 4, GL_UNSIGNED_BYTE, GL_TRUE, RENDERER_VERTEX_SIZE, (const GLvoid *)offsetof(VertexData, VertexData::colour));
            glBindBuffer(GL_ARRAY_BUFFER, 0);

            GLuint *indices = new GLuint[RENDERER_INDICES_SIZE];

            int offset = 0;
            for (int i {0}; i < RENDERER_INDICES_SIZE; i+=6)
            {
                indices[i] = offset;
                indices[i + 1] = offset + 1;
                indices[i + 2] = offset + 2;

                indices[i + 3] = offset + 2;
                indices[i + 4] = offset + 3;
                indices[i + 5] = offset;

                offset += 4;
            }

            m_IBO = new IndexBuffer(indices, RENDERER_INDICES_SIZE);

            glBindVertexArray(0);
        }

        void BatchRenderer2D::begin()
        {
            glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
            m_Buffer = (VertexData *)glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);
        }

        void BatchRenderer2D::end()
        {
            glUnmapBuffer(GL_ARRAY_BUFFER);
            glBindBuffer(GL_ARRAY_BUFFER, 0);
        }

        void BatchRenderer2D::submit(const Renderable2D* t_Renderable)
        {
            const Math::vec3 &position = t_Renderable->getPosition();
            const Math::vec4 &colour = t_Renderable->getColour();
            const Math::vec2 &size = t_Renderable->getSize();

            int r = colour.x * 255.0f;
            int g = colour.y * 255.0f;
            int b = colour.z * 255.0f;
            int a = colour.w * 255.0f;

            unsigned int c = a << 24 | b << 16 | g << 8 | r;

            m_Buffer->vertex = (*m_TransformationBack) * position;
            m_Buffer->colour = c;
            m_Buffer++;
            
            m_Buffer->vertex = (*m_TransformationBack) * Math::vec3(position.x, position.y + size.y, position.z);
            m_Buffer->colour = c;
            m_Buffer++;
            
            m_Buffer->vertex = (*m_TransformationBack) * Math::vec3(position.x + size.x, position.y + size.y, position.z);
            m_Buffer->colour = c;
            m_Buffer++;
            
            m_Buffer->vertex = (*m_TransformationBack) * Math::vec3(position.x + size.x, position.y, position.z);;
            m_Buffer->colour = c;
            m_Buffer++;

            m_IndexCount += 6;
        }

        void BatchRenderer2D::flush()
        {
            glBindVertexArray(m_VAO);
            m_IBO->bind();
            
            glDrawElements(GL_TRIANGLES, m_IndexCount, GL_UNSIGNED_INT, NULL);

            m_IBO->unbind();
            glBindVertexArray(0);

            m_IndexCount = 0;
        }

    }
}