#pragma once

#include "../include/Vector3.hpp"
#include <algorithm>
#include <cmath>

constexpr float PI = 3.14159265358979323846f;
constexpr float HALF_PI = PI / 180.f;
constexpr float TAU = 2.f * PI;

namespace rtx
{
    class MathUtils 
    {
    public:
        template <typename T>
        static T Max3(T a, T b, T c) { return std::max(std::max(a, b), c); }

        template <typename T>
        static T Min3(T a, T b, T c) { return std::min(std::min(a, b), c); }

        template <typename T> 
        static T Clamp(const T value, const T min, const T max)
        {
            if (value < min)
            {
                return min;
            }

            if (value > max)
            {
                return max;
            }

            return value;
        }

        static float DegToRad(const float degrees) 
        { 
            return degrees * (PI / 180.0f); 
        }

        static float RadToDeg(const float radians) 
        {
            return radians * (180.0f / PI);
        }

        static Vector3 Refract(Vector3 I, Vector3 N, const float& ior)
        {
            float cosine = std::fmin(-I.Dot(N), 1.f);

            Vector3 perp = (I + N * cosine) * ior;
            Vector3 paral = N * -std::sqrt(std::fabs(1.f - perp.Length() * perp.Length()));
            
            return perp + paral;
        }

        static Vector3 Reflect(Vector3 I, Vector3 N)
        {
            return I - N * 2 * I.Dot(N);
        }
    };
}
