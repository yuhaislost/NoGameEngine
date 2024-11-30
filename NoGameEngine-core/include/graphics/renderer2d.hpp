#pragma once
#include <vector>
#include <GL/glew.h>
#include "math/math.hpp"

namespace NoGameEngine
{
    namespace Graphics
    {
        class Renderable2D;
        
        class Renderer2D
        {
            public:
                void push(const Math::mat4& t_Matrix, bool t_Override = false)
                {
                    if (t_Override)
                        m_TransformationStack.push_back(t_Matrix);
                    else
                        m_TransformationStack.push_back(m_TransformationStack.back() * t_Matrix);
                    
                    m_TransformationBack = &m_TransformationStack.back();
                }

                void pop()
                {
                    if (m_TransformationStack.size() > 1)
                        m_TransformationStack.pop_back();

                    m_TransformationBack = &m_TransformationStack.back();
                }

                virtual void begin() {}
                virtual void end() {}
                virtual void submit(const Renderable2D *t_Renderable) = 0;
                virtual void flush() = 0;

            protected:
                Renderer2D()
                {
                    m_TransformationStack.push_back(Math::mat4::identity());
                    m_TransformationBack = &m_TransformationStack.back();
                }

            protected:
                std::vector<Math::mat4> m_TransformationStack;
                const Math::mat4* m_TransformationBack;
        };
    }
}