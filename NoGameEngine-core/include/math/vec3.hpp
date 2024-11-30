#pragma once
#include <iostream>

namespace NoGameEngine
{
    namespace Math
    {
        struct vec3
        {
            float x, y, z;

            vec3() = default;
            vec3(const float& t_X, const float& t_Y, const float &t_Z);

            vec3& add(const vec3& t_Other);
            vec3& substract(const vec3& t_Other);
            vec3& multiply(const vec3& t_Other);
            vec3& divide(const vec3& t_Other);
            bool equal(const vec3& t_Other) const;
            bool nequal(const vec3& t_Other) const;

            friend vec3 operator+(vec3 t_Left, const vec3 &t_Right);
            friend vec3 operator-(vec3 t_Left, const vec3 &t_Right);
            friend vec3 operator*(vec3 t_Left, const vec3 &t_Right);
            friend vec3 operator/(vec3 &t_Left, const vec3 &t_Right);
            bool operator==(const vec3& t_Other);
            bool operator!=(const vec3& t_Other);
            
            vec3& operator+=(const vec3& t_Other);
            vec3& operator-=(const vec3& t_Other);
            vec3& operator*=(const vec3& t_Other);
            vec3& operator/=(const vec3& t_Other);

            friend std::ostream& operator<<(std::ostream& t_OS, const vec3& t_Vector);
        };
        
    }   
}
