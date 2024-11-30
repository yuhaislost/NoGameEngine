#include "graphics/layers/tilelayer.hpp"

namespace NoGameEngine
{
    namespace Graphics
    {
        TileLayer::TileLayer(Shader *t_Shader)
            : Layer(new BatchRenderer2D(), t_Shader, Math::mat4::orthographic(-16.0f, 16.0f, -9.0f, 9.0f, -1.0f, 1.0f))
        {
        }

        TileLayer::~TileLayer()
        {
        }

    }
}