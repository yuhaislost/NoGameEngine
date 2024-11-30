#include "graphics/simple2drenderer.hpp"
#include "graphics/renderable2d.hpp"

namespace NoGameEngine
{
    namespace Graphics
    {
        void Simple2DRenderer::submit(const Renderable2D *t_Renderable)
        {
            m_RenderQueue.push_back((StaticSprite *)t_Renderable);
        }

        void Simple2DRenderer::flush()
        {
            while (!m_RenderQueue.empty())
            {
                const StaticSprite* sprite = m_RenderQueue.front();
                sprite->getVAO()->bind();
                sprite->getIBO()->bind();

                sprite->getShader().setUniformMat4("ml_matrix", Math::mat4::translation(sprite->getPosition()));
                glDrawElements(GL_TRIANGLES, sprite->getIBO()->getCount(), GL_UNSIGNED_SHORT, 0);


                sprite->getIBO()->unbind();
                sprite->getVAO()->unbind();
                m_RenderQueue.pop_front();
            }
            
        }
    }
}