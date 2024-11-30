#include "math/vec4.hpp"

namespace NoGameEngine
{
    namespace Math
    {
        vec4::vec4(const float &t_X, const float &t_Y, const float &t_Z, const float &t_W) : x(t_X), y(t_Y), z(t_Z), w(t_W) {}

        vec4& vec4::add(const vec4 &t_Other)
        {
            x += t_Other.x;
            y += t_Other.y;
            z += t_Other.z;
            w += t_Other.w;
            return *this;
        }

        vec4& vec4::substract(const vec4 &t_Other)
        {
            x -= t_Other.x;
            y -= t_Other.y;
            z -= t_Other.z;
            w -= t_Other.w;
            return *this;
        }

        vec4& vec4::multiply(const vec4 &t_Other)
        {
            x *= t_Other.x;
            y *= t_Other.y;
            z *= t_Other.z;
            w *= t_Other.w;
            return *this;
        }

        vec4& vec4::divide(const vec4 &t_Other)
        {
            x /= t_Other.x;
            y /= t_Other.y;
            z /= t_Other.z;
            w /= t_Other.w;
            return *this;
        }

        bool vec4::equal(const vec4 &t_Other) const
        {
            return (x == t_Other.x && y == t_Other.y && z == t_Other.z && w == t_Other.w);
        }

        bool vec4::nequal(const vec4& t_Other) const
        {
            return !equal(t_Other);
        }
        
        vec4 operator+(vec4 t_Left, const vec4 &t_Right)
        {
            return t_Left.add(t_Right);
        }

        vec4 operator-(vec4 t_Left, const vec4 &t_Right)
        {
            return t_Left.substract(t_Right);
        }

        vec4 operator*(vec4 t_Left, const vec4 &t_Right)
        {
            return t_Left.multiply(t_Right);
        }

        vec4 operator/(vec4 t_Left, const vec4 &t_Right)
        {
            return t_Left.divide(t_Right);
        }

        bool vec4::operator==(const vec4& t_Other)
        {
            return equal(t_Other);
        }

        bool vec4::operator!=(const vec4& t_Other)
        {
            return nequal(t_Other);
        }

        vec4& vec4::operator+=(const vec4& t_Other)
        {
            return add(t_Other);
        }

        vec4& vec4::operator-=(const vec4& t_Other)
        {
            return substract(t_Other);
        }

        vec4& vec4::operator*=(const vec4& t_Other)
        {
            return multiply(t_Other);
        }

        vec4& vec4::operator/=(const vec4& t_Other)
        {
            return multiply(t_Other);
        }

        std::ostream& operator<<(std::ostream &t_OS, const vec4 & t_Vector)
        {
            t_OS << t_Vector.x << ", " << t_Vector.y << ", " << t_Vector.z << ", " << t_Vector.w;
            return t_OS;
        }
    }   
}
