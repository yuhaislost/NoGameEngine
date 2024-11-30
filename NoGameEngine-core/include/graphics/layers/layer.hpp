#pragma once
#include "graphics/renderable2d.hpp"
#include "graphics/renderer2d.hpp"

namespace NoGameEngine
{
    namespace Graphics
    {
        class Layer
        {
            protected:
                Layer(Renderer2D *t_Renderer, Shader *t_Shader, Math::mat4 t_ProjectionMatrix);

            public:
                virtual ~Layer();
                virtual void add(Renderable2D* t_Renderable);
                virtual void render();

            protected:
                Renderer2D* m_Renderer;
                std::vector<Renderable2D *> m_Renderables;
                Shader* m_Shader;
                Math::mat4 m_ProjectionMatrix;
        };
    }
}