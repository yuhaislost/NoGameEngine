#pragma once
#include "graphics/layers/layer.hpp"
#include "graphics/batchrenderer2d.hpp"

namespace NoGameEngine
{
    namespace Graphics
    {
        class TileLayer : public Layer
        {
            public:
                TileLayer(Shader *t_Shader);
                ~TileLayer();
        };
    }
}