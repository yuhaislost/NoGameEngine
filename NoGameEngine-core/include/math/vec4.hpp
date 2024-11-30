#pragma once
#include <iostream>

namespace NoGameEngine
{
    namespace Math
    {
        struct vec4
        {
            float x, y, z, w;

            vec4() = default;
            vec4(const float& t_X, const float& t_Y, const float &t_Z, const float &t_W);

            vec4& add(const vec4& t_Other);
            vec4& substract(const vec4& t_Other);
            vec4& multiply(const vec4& t_Other);
            vec4& divide(const vec4& t_Other);
            bool equal(const vec4& t_Other) const;
            bool nequal(const vec4& t_Other) const;

            friend vec4 operator+(vec4 t_Left, const vec4 &t_Right);
            friend vec4 operator-(vec4 t_Left, const vec4 &t_Right);
            friend vec4 operator*(vec4 t_Left, const vec4 &t_Right);
            friend vec4 operator/(vec4 t_Left, const vec4 &t_Right);
            bool operator==(const vec4& t_Other);
            bool operator!=(const vec4& t_Other);
            
            vec4& operator+=(const vec4& t_Other);
            vec4& operator-=(const vec4& t_Other);
            vec4& operator*=(const vec4& t_Other);
            vec4& operator/=(const vec4& t_Other);

            friend std::ostream& operator<<(std::ostream& t_OS, const vec4& t_Vector);
        };
        
    }   
}
