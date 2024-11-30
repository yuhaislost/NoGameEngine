#pragma once

#include "math/math.hpp"

namespace NoGameEngine
{
    namespace Math
    {
        struct mat4
        {
            union
            {
                float elements[16];
                vec4 columns[4];
            };

            mat4();
            mat4(float t_Diagonal);

            static mat4 identity();

            mat4& multiply(const mat4& t_Other);
            friend mat4 operator*(mat4 t_Left, const mat4 &t_Right);
            mat4& operator*=(const mat4& t_Other);

            vec3 multiply(const vec3& t_Other) const;
            friend vec3 operator*(const mat4 t_Left, const vec3& t_Right);

            vec4 multiply(const vec4& t_Other) const;
            friend vec4 operator*(const mat4 t_Left, const vec4& t_Right);

            static mat4 orthographic(float t_Left, float t_Right, float t_Top, float t_Bottom, float t_Near, float t_Far);
            static mat4 perspective(float t_Fov, float t_AspectRatio, float t_Near, float t_Far);

            static mat4 translation(const vec3& t_Translation);
            static mat4 rotation(float t_Angle, const vec3 &t_Axis);
            static mat4 scale(const vec3& t_Scale);
        };
    } 
}
