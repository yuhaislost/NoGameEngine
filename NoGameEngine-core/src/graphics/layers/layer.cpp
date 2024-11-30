#include "graphics/layers/layer.hpp"

namespace NoGameEngine
{
    namespace Graphics
    {
        Layer::Layer(Renderer2D *t_Renderer, Shader *t_Shader, Math::mat4 t_ProjectionMatrix)
            : m_Renderer(t_Renderer), m_Shader(t_Shader), m_ProjectionMatrix(t_ProjectionMatrix)
        {
            m_Shader->enable();
            m_Shader->setUniformMat4("pr_matrix", m_ProjectionMatrix);
            m_Shader->disable();
        }

        Layer::~Layer()
        {
            delete m_Shader;
            delete m_Renderer;

            for (int i {0}; i < m_Renderables.size(); i++)
                delete m_Renderables[i];
        }

        void Layer::add(Renderable2D* t_Renderable)
        {
            m_Renderables.push_back(t_Renderable);
        }

        void Layer::render()
        {
            m_Shader->enable();
            m_Renderer->begin();
            for (const Renderable2D* renderable : m_Renderables)
                renderable->submit(m_Renderer);
            m_Renderer->end();
            m_Renderer->flush();
        }
    }
}