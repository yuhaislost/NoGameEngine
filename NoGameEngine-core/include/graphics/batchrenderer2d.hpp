#pragma once

#include <cstddef>
#include "Graphics/renderer2d.hpp"
#include "Graphics/buffers/indexbuffer.hpp"
#include "graphics/renderable2d.hpp"

namespace NoGameEngine
{
    namespace Graphics
    {
        
        #define RENDERER_MAX_SPRITES    60000
        #define RENDERER_VERTEX_SIZE    sizeof(VertexData)
        #define RENDERER_SPRITE_SIZE    RENDERER_VERTEX_SIZE * 4
        #define RENDERER_BUFFER_SIZE    RENDERER_SPRITE_SIZE * RENDERER_MAX_SPRITES
        #define RENDERER_INDICES_SIZE   RENDERER_MAX_SPRITES * 6
        
        #define SHADER_VERTEX_INDEX 0
        #define SHADER_COLOUR_INDEX 1

        class BatchRenderer2D : public Renderer2D
        {
            public:
                BatchRenderer2D();
                ~BatchRenderer2D();
                void begin() override;
                void end() override;
                void submit(const Renderable2D *t_Renderable) override;
                void flush() override;

            private:
                void init();

            private:
                GLuint m_VAO;
                GLuint m_VBO;
                IndexBuffer* m_IBO;

                GLsizei m_IndexCount;
                VertexData* m_Buffer;
        };
    }
}