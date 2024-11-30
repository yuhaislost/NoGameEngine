#include "math/vec2.hpp"

namespace NoGameEngine
{
    namespace Math
    {
        vec2::vec2(const float &t_X, const float &t_Y) : x(t_X), y(t_Y) {}

        vec2& vec2::add(const vec2 &t_Other)
        {
            x += t_Other.x;
            y += t_Other.y;
            return *this;
        }

        vec2& vec2::substract(const vec2 &t_Other)
        {
            x -= t_Other.x;
            y -= t_Other.y;
            return *this;
        }

        vec2& vec2::multiply(const vec2 &t_Other)
        {
            x *= t_Other.x;
            y *= t_Other.y;
            return *this;
        }

        vec2& vec2::divide(const vec2 &t_Other)
        {
            x /= t_Other.x;
            y /= t_Other.y;
            return *this;
        }

        bool vec2::equal(const vec2 &t_Other) const
        {
            return (x == t_Other.x && y == t_Other.y);
        }

        bool vec2::nequal(const vec2& t_Other) const
        {
            return !equal(t_Other);
        }
        
        vec2 operator+(vec2 t_Left, const vec2 &t_Right)
        {
            return t_Left.add(t_Right);
        }

        vec2 operator-(vec2 t_Left, const vec2 &t_Right)
        {
            return t_Left.substract(t_Right);
        }

        vec2 operator*(vec2 t_Left, const vec2 &t_Right)
        {
            return t_Left.multiply(t_Right);
        }

        vec2 operator/(vec2 t_Left, const vec2 &t_Right)
        {
            return t_Left.divide(t_Right);
        }

        bool vec2::operator==(const vec2& t_Other)
        {
            return equal(t_Other);
        }

        bool vec2::operator!=(const vec2& t_Other)
        {
            return nequal(t_Other);
        }

        vec2& vec2::operator+=(const vec2& t_Other)
        {
            return add(t_Other);
        }

        vec2& vec2::operator-=(const vec2& t_Other)
        {
            return substract(t_Other);
        }

        vec2& vec2::operator*=(const vec2& t_Other)
        {
            return multiply(t_Other);
        }

        vec2& vec2::operator/=(const vec2& t_Other)
        {
            return multiply(t_Other);
        }

        std::ostream& operator<<(std::ostream &t_OS, const vec2 & t_Vector)
        {
            t_OS << t_Vector.x << ", " << t_Vector.y;
            return t_OS;
        }
    }   
}
