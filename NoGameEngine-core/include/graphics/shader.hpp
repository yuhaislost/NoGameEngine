#pragma once

#include "utils/fileutility.hpp"
#include "math/math.hpp"
#include <GL/glew.h>
#include <vector>
#include <iostream>

namespace NoGameEngine
{
    namespace Graphics
    {
        class Shader
        {
            public:

                Shader(const char* t_VertexPath, const char* t_FragmentPath);
                ~Shader();

                void setUniform1f(const GLchar* t_Name, float t_Val);
                void setUniform2f(const GLchar* t_Name, const Math::vec2& t_Vec2);
                void setUniform3f(const GLchar* t_Name, const Math::vec3& t_Vec3);
                void setUniform4f(const GLchar* t_Name, const Math::vec4& t_Vec4);
                void setUniform1i(const GLchar* t_Name, int t_Val);

                void setUniformMat4(const GLchar* t_Name, const Math::mat4& t_Matrix);

                void enable() const;
                void disable() const;

                inline GLuint getID() { return m_ShaderID; }

            private:
                
                GLint getUniformLocation(const GLchar *t_Name);
                GLuint load();

            private:

                GLuint m_ShaderID;
                const char* m_VertexPath;
                const char* m_FragmentPath;

        };
    }
}