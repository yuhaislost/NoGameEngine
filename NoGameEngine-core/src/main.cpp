#include <iostream>
#include <vector>
#include <time.h>
#include "graphics/window.hpp"
#include "math/math.hpp"
#include "graphics/shader.hpp"
#include "utils/fileutility.hpp"
#include "graphics/buffers/buffer.hpp"
#include "graphics/buffers/indexbuffer.hpp"
#include "graphics/buffers/vertexarray.hpp"
#include "graphics/simple2drenderer.hpp"
#include "graphics/batchrenderer2d.hpp"
#include "graphics/renderable2d.hpp"
#include "graphics/staticsprite.hpp"
#include "graphics/sprite.hpp"
#include "utils/timer.hpp"
#include "graphics/layers/tilelayer.hpp"
#include "graphics/layers/group.hpp"

#define BATCHRENDERER 1

using namespace NoGameEngine;

int main()
{
    Graphics::Window window {"Basic Window", 1920, 1080};

    Math::mat4 ortho = Math::mat4::orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);
    Graphics::Shader *bufferShader = new Graphics::Shader{"../../NoGameEngine-core/src/shaders/basic.vert", "../../NoGameEngine-core/src/shaders/basic.frag"};
    Graphics::Shader *bufferShader2 = new Graphics::Shader{"../../NoGameEngine-core/src/shaders/basic.vert", "../../NoGameEngine-core/src/shaders/basic.frag"};
    Graphics::Shader& shader = *bufferShader;
    Graphics::Shader& shader2 = *bufferShader2;

    shader.enable();
    shader2.enable();
    shader.setUniform2f("light_pos", Math::vec2(4.0f, 1.5f));
    shader2.setUniform2f("light_pos", Math::vec2(4.0f, 1.5f));

    Graphics::TileLayer layer {&shader};
    Graphics::Group* group = new Graphics::Group(Math::mat4::translation(Math::vec3(-15.0f, 5.0f, 0.0f)));
    group->add(new Graphics::Sprite(0.0f, 0.0f, 6, 3, Math::vec4(1, 1, 1, 1)));
    group->add(new Graphics::Sprite(0.5f, 0.5f, 5.0f, 2.0f, Math::vec4(1, 0, 1, 1)));
    layer.add(group);

    Graphics::TileLayer layer2 {&shader2};
    layer2.add(new Graphics::Sprite(-2, -2, 6, 3, Math::vec4(1, 0, 1, 1)));

    Utils::Timer time;
    float timer {0};
    unsigned int frames {0};
    while (!window.closed())
    {
        window.clear();
        double x,y;
        window.getMousePosition(x,y);
        shader.enable();
        shader.setUniform2f("light_pos", Math::vec2((float)(x * 32.0f / 1920.0f - 16.0f), (float)(9.0f - y * 18.0f / 1080.0f)));
        // shader2.enable();
        // shader2.setUniform2f("light_pos", Math::vec2((float)(x * 32.0f / 1920.0f - 16.0f), (float)(9.0f - y * 18.0f / 1080.0f)));
        layer.render();
        // layer2.render();
        window.update();
        frames++;
        if (time.elasped() - timer > 1.0f)
        {
            timer += 1.0f;
            std::cout << frames <<  "fps" << std::endl;
            frames = 0;
        }
    }
}