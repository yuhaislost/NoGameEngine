#pragma once

#define _USE_MATH_DEFINES
#include <math.h>

namespace NoGameEngine
{
    namespace Math
    {
        inline float toRadians(float t_Degrees)
        {
            return t_Degrees * (M_PI / 180.0f);
        }
    }   
}