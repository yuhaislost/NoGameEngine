#include "graphics/sprite.hpp"

namespace NoGameEngine
{
    namespace Graphics
    {
        Sprite::Sprite(float t_X, float t_Y, float t_Width, float t_Height, const Math::vec4 &t_Colour)
            : Renderable2D(Math::vec3(t_X, t_Y, 0), Math::vec2(t_Width, t_Height), t_Colour)
        {
            
        }
    }
}