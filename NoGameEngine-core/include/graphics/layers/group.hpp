#pragma once
#include "graphics/renderable2d.hpp"

namespace NoGameEngine
{
    namespace Graphics
    {
        class Group : public Renderable2D
        {
            public:
                Group(const Math::mat4& t_Transform);
                void submit(Renderer2D* t_Renderer) const override;
                void add (Renderable2D* t_Renderable);

            private:
                std::vector<Renderable2D *> m_Renderables;
                Math::mat4 m_TransformationMatrix;
        };
    }
}