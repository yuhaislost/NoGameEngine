#include "math/vec3.hpp"

namespace NoGameEngine
{
    namespace Math
    {
        vec3::vec3(const float &t_X, const float &t_Y, const float &t_Z) : x(t_X), y(t_Y), z(t_Z) {}

        vec3& vec3::add(const vec3 &t_Other)
        {
            x += t_Other.x;
            y += t_Other.y;
            z += t_Other.z;
            return *this;
        }

        vec3& vec3::substract(const vec3 &t_Other)
        {
            x -= t_Other.x;
            y -= t_Other.y;
            z -= t_Other.z;
            return *this;
        }

        vec3& vec3::multiply(const vec3 &t_Other)
        {
            x *= t_Other.x;
            y *= t_Other.y;
            z *= t_Other.z;
            return *this;
        }

        vec3& vec3::divide(const vec3 &t_Other)
        {
            x /= t_Other.x;
            y /= t_Other.y;
            z /= t_Other.z;
            return *this;
        }

        bool vec3::equal(const vec3 &t_Other) const
        {
            return (x == t_Other.x && y == t_Other.y && z == t_Other.z);
        }

        bool vec3::nequal(const vec3& t_Other) const
        {
            return !equal(t_Other);
        }
        
        vec3 operator+(vec3 t_Left, const vec3 &t_Right)
        {
            return t_Left.add(t_Right);
        }

        vec3 operator-(vec3 t_Left, const vec3 &t_Right)
        {
            return t_Left.substract(t_Right);
        }

        vec3 operator*(vec3 t_Left, const vec3 &t_Right)
        {
            return t_Left.multiply(t_Right);
        }

        vec3& operator/(vec3 t_Left, const vec3 &t_Right)
        {
            return t_Left.divide(t_Right);
        }

        bool vec3::operator==(const vec3& t_Other)
        {
            return equal(t_Other);
        }

        bool vec3::operator!=(const vec3& t_Other)
        {
            return nequal(t_Other);
        }

        vec3& vec3::operator+=(const vec3& t_Other)
        {
            return add(t_Other);
        }

        vec3& vec3::operator-=(const vec3& t_Other)
        {
            return substract(t_Other);
        }

        vec3& vec3::operator*=(const vec3& t_Other)
        {
            return multiply(t_Other);
        }

        vec3& vec3::operator/=(const vec3& t_Other)
        {
            return multiply(t_Other);
        }

        std::ostream& operator<<(std::ostream &t_OS, const vec3 & t_Vector)
        {
            t_OS << t_Vector.x << ", " << t_Vector.y << ", " << t_Vector.z;
            return t_OS;
        }
    }   
}
