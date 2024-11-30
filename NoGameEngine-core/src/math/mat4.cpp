#include "math/mat4.hpp"

namespace NoGameEngine
{
    namespace Math
    {
        mat4::mat4()
        {
            for (int i {0}; i < 16; i++)
                elements[i] = 0.0f;
        }

        mat4::mat4(float t_Diagonal)
        {
            for (int y {0}; y < 4; y++)
            {
                for (int x {0}; x < 4; x++)
                {
                    if (x == y)
                        elements[y * 4 + x] = t_Diagonal;
                    else
                        elements[y * 4 + x] = 0.0f;
                }
            }
        }

        mat4 mat4::identity()
        {
            return mat4(1.0f);
        }

        mat4& mat4::multiply(const mat4 &t_Other)
        {
            float data[16];
            for (int y {0}; y < 4; y++)
            {
                for (int x {0}; x < 4; x++)
                {
                    float sum = 0.0f;
                    for (int e {0}; e < 4; e++)
                    {
                        sum += elements[e * 4 + x] * t_Other.elements[y * 4 + e];
                    }
                    data[y * 4 + x] = sum;
                }
            }

            memcpy(elements, data, 4 * 4 * sizeof(float));

            return *this;
        }

        vec4 mat4::multiply(const vec4& t_Other) const
        {
            return vec4(
                columns[0].x * t_Other.x + columns[1].x * t_Other.y + columns[2].x * t_Other.z + columns[3].x * t_Other.w,
                columns[0].y * t_Other.x + columns[1].y * t_Other.y + columns[2].y * t_Other.z + columns[3].y * t_Other.w,
                columns[0].z * t_Other.x + columns[1].z * t_Other.y + columns[2].z * t_Other.z + columns[3].z * t_Other.w,
                columns[0].w * t_Other.x + columns[1].w * t_Other.y + columns[2].w * t_Other.z + columns[3].w * t_Other.w
            );
        }

        vec3 mat4::multiply(const vec3& t_Other) const
        {
            return vec3(
                columns[0].x * t_Other.x + columns[1].x * t_Other.y + columns[2].x * t_Other.z,
                columns[0].y * t_Other.x + columns[1].y * t_Other.y + columns[2].y * t_Other.z,
                columns[0].z * t_Other.x + columns[1].z * t_Other.y + columns[2].z * t_Other.z
            );
        }
        
        mat4 operator*(mat4 t_Left, const mat4 &t_Right)
        {
            return t_Left.multiply(t_Right);
        }
        
        mat4& mat4::operator*=(const mat4& t_Other)
        {
            return multiply(t_Other);
        }

        vec3 operator*(const mat4 t_Left, const vec3& t_Right)
        {
            return t_Left.multiply(t_Right);
        }

        vec4 operator*(const mat4 t_Left, const vec4& t_Right)
        {
            return t_Left.multiply(t_Right);
        }

        
        mat4 mat4::orthographic(float t_Left, float t_Right, float t_Bottom, float t_Top, float t_Near, float t_Far)
        {
            mat4 result {1.0f};

            result.elements[0 + 0 * 4] = 2.0f / (t_Right - t_Left);
            result.elements[1 + 1 * 4] = 2.0f / (t_Top - t_Bottom);
            result.elements[2 + 2 * 4] = 2.0f / (t_Near - t_Far);

            result.elements[0 + 3 * 4] = (t_Left + t_Right) / (t_Left - t_Right);
            result.elements[1 + 3 * 4] = (t_Bottom + t_Top) / (t_Bottom - t_Top);
            result.elements[2 + 3 * 4] = (t_Far + t_Near) / (t_Far - t_Near);

            return result;
        }

        mat4 mat4::perspective(float t_Fov, float t_AspectRatio, float t_Near, float t_Far)
        {
            mat4 result {1.0f};
            float a = 1.0f / tan(toRadians(0.5f * t_Fov));
            float b = a / t_AspectRatio;
            float c = (t_Near + t_Far) / (t_Near - t_Far);
            float d = (2.0f * t_Near * t_Far) / (t_Near - t_Far);

            result.elements[0 + 0 * 4] = b;
            result.elements[1 + 1 * 4] = a;
            result.elements[2 + 2 * 4] = c;
            result.elements[3 + 2 * 4] = -1.0f;
            result.elements[2 + 3 * 4] = d;

            return result;
        }

        mat4 mat4::translation(const vec3& t_Translation)
        {
            mat4 result {1.0f};

            result.elements[0 + 3 * 4] = t_Translation.x;
            result.elements[1 + 3 * 4] = t_Translation.y;
            result.elements[2 + 3 * 4] = t_Translation.z;

            return result;
        }

        mat4 mat4::rotation(float t_Angle, const vec3 &t_Axis)
        {
            mat4 result {1.0f};

            float rAngle = toRadians(t_Angle);
            float cAngle = cos(rAngle);
            float sAngle = sin(rAngle);
            float mcAngle = 1.0f - cAngle;

            float x = t_Axis.x;
            float y = t_Axis.y;
            float z = t_Axis.z;

            result.elements[0 + 0 * 4] = x * mcAngle + cAngle;
            result.elements[1 + 0 * 4] = y * x * mcAngle + z * sAngle;
            result.elements[2 + 0 * 4] = x * z * mcAngle - y * sAngle;

            result.elements[0 + 1 * 4] = x * y * mcAngle - z * sAngle;
            result.elements[1 + 1 * 4] = y * mcAngle + cAngle; 
            result.elements[2 + 1 * 4] = y * z * mcAngle + x * sAngle;
            
            result.elements[0 + 2 * 4] = x * z * mcAngle + y * sAngle;
            result.elements[1 + 2 * 4] = y * z * mcAngle - x * sAngle; 
            result.elements[2 + 2 * 4] = z * mcAngle + cAngle;

            return result;
        }

        mat4 mat4::scale(const vec3& t_Scale)
        {
            mat4 result {1.0f};

            result.elements[0 + 0 * 4] = t_Scale.x;
            result.elements[1 + 1 * 4] = t_Scale.y;
            result.elements[2 + 2 * 4] = t_Scale.z;

            return result;
        }


    }
       
}