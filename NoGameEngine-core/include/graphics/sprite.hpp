#pragma once

#include "graphics/renderable2d.hpp"

namespace NoGameEngine
{
    namespace Graphics
    {
        class Sprite : public Renderable2D
        {
            public:
                Sprite(float t_X, float t_Y, float t_Width, float t_Height, const Math::vec4 &t_Colour);
                
            private:

        };
    }
}