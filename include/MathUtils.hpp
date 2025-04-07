#pragma once

#include <algorithm>
#include <cmath>

constexpr float PI = 3.14159265358979323846;

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
    };
}
