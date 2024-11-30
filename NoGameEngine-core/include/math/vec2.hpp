#pragma once
#include <iostream>

namespace NoGameEngine
{
    namespace Math
    {
        struct vec2
        {
            float x,y;

            vec2() = default;
            vec2(const float& t_X, const float& t_Y);

            vec2& add(const vec2& t_Other);
            vec2& substract(const vec2& t_Other);
            vec2& multiply(const vec2& t_Other);
            vec2& divide(const vec2& t_Other);
            bool equal(const vec2& t_Other) const;
            bool nequal(const vec2& t_Other) const;

            friend vec2 operator+(vec2 t_Left, const vec2 &t_Right);
            friend vec2 operator-(vec2 t_Left, const vec2 &t_Right);
            friend vec2 operator*(vec2 t_Left, const vec2 &t_Right);
            friend vec2 operator/(vec2 t_Left, const vec2 &t_Right);
            bool operator==(const vec2& t_Other);
            bool operator!=(const vec2& t_Other);

            vec2& operator+=(const vec2& t_Other);
            vec2& operator-=(const vec2& t_Other);
            vec2& operator*=(const vec2& t_Other);
            vec2& operator/=(const vec2& t_Other);

            friend std::ostream& operator<<(std::ostream &t_OS, const vec2 & t_Vector);
        };
        
    }   
}
