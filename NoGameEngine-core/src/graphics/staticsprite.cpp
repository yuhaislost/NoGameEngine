#include "graphics/staticsprite.hpp"

namespace NoGameEngine
{
    namespace Graphics
    {
        StaticSprite::StaticSprite(float t_X, float t_Y, float t_Width, float t_Height, const Math::vec4 &t_Colour, Shader &t_Shader) 
            : Renderable2D(Math::vec3(t_X, t_Y, 0), Math::vec2(t_Width, t_Height), t_Colour), m_Shader(t_Shader)
        {
            m_VertexArray = new VertexArray();
            GLfloat vertices[] = 
            {
                0, 0, 0,
                0, t_Height, 0,
                t_Width, t_Height, 0,
                t_Width, 0, 0
            };

            GLfloat colour[] = 
            {
                t_Colour.x, t_Colour.y, t_Colour.z, t_Colour.w,
                t_Colour.x, t_Colour.y, t_Colour.z, t_Colour.w,
                t_Colour.x, t_Colour.y, t_Colour.z, t_Colour.w,
                t_Colour.x, t_Colour.y, t_Colour.z, t_Colour.w
            };
            
            m_VertexArray->addBuffer(new Buffer(vertices, 4 *3, 3), 0);
            m_VertexArray->addBuffer(new Buffer(colour, 4 *4, 4), 1);

            GLushort indices[] = { 0, 1, 2, 2, 3, 0 };
            m_IndexBuffer = new IndexBuffer(indices, 6);
        }

        StaticSprite::~StaticSprite()
        {
            delete m_VertexArray;
            delete m_IndexBuffer;
        }
    }
}