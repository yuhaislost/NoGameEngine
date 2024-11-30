#include "graphics/layers/group.hpp"

namespace NoGameEngine
{
    namespace Graphics
    {
        Group::Group(const Math::mat4& t_Transform) : m_TransformationMatrix(t_Transform) {}

        void Group::submit(Renderer2D* t_Renderer) const
        {
            t_Renderer->push(m_TransformationMatrix);
            for (const Renderable2D* renderable : m_Renderables)
                t_Renderer->submit(renderable);
            t_Renderer->pop();
        }

        void Group::add(Renderable2D* t_Renderable)
        {
            m_Renderables.push_back(t_Renderable);
        }
    }
}