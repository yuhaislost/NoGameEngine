#pragma once

#include "graphics/buffers/buffer.hpp"
#include "graphics/buffers/indexbuffer.hpp"
#include "graphics/buffers/vertexarray.hpp"
#include "math/math.hpp"
#include "graphics/shader.hpp"
#include "graphics/renderer2d.hpp"

namespace NoGameEngine
{
    namespace Graphics
    {
        struct VertexData
        {
            Math::vec3 vertex;
            unsigned int colour;
        };

        class Renderable2D
        {
            public:
                Renderable2D(Math::vec3 t_Position, Math::vec2 t_Size, Math::vec4 t_Colour)
                    : m_Position(t_Position), m_Size(t_Size), m_Colour(t_Colour)
                {}

                virtual ~Renderable2D() {}

                virtual void submit(Renderer2D* t_Renderer) const
                {
                    t_Renderer->submit(this);
                }

                inline const Math::vec3& getPosition() const { return m_Position; }
                inline const Math::vec2& getSize() const { return m_Size; }
                inline const Math::vec4& getColour() const { return m_Colour; }
    
            protected:
                Renderable2D() {}

            protected:

                Math::vec3 m_Position;
                Math::vec2 m_Size;
                Math::vec4 m_Colour;
        };
    }
}