#pragma once

#include "graphics/renderable2d.hpp"

namespace NoGameEngine
{
    namespace Graphics
    {
        class StaticSprite : public Renderable2D
        {
            public:
                StaticSprite(float t_X, float t_Y, float t_Width, float t_Height, const Math::vec4 &t_Colour, Shader &t_Shader);
                ~StaticSprite();
                
                inline Shader& getShader() const { return m_Shader; }
                inline const VertexArray* getVAO() const { return m_VertexArray; }
                inline const IndexBuffer* getIBO() const { return m_IndexBuffer; }
                
            private:
                VertexArray* m_VertexArray;
                IndexBuffer* m_IndexBuffer;
                Shader& m_Shader;
        };
    }
}