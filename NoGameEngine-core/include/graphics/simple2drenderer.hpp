#pragma once
#include <deque>
#include "graphics/staticsprite.hpp"

namespace NoGameEngine
{
    namespace Graphics
    {
        class Simple2DRenderer : public Renderer2D
        {
            public:
                void submit(const Renderable2D *t_Renderable) override;
                void flush() override;

            private:
                std::deque<const StaticSprite*> m_RenderQueue;
        };
    }
}