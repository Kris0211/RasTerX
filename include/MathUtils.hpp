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


        static Vector3 Refract(const Vector3& I, const Vector3& N, const float& ior) 
        {
            Vector3 normalizedI = I.Normal();
            Vector3 normalizedN = N.Normal();

            float cosi = -normalizedI.Dot(normalizedN);
            float etai = 1.0f;
            float etat = ior;

            if (cosi < 0) 
            {
                cosi = -cosi;
                std::swap(etai, etat);
                normalizedN = -normalizedN;
            }

            const float eta = etai / etat;
            const float k = 1.0f - eta * eta * (1.0f - cosi * cosi);

            if (k < 0) 
            {
                return Reflect(I, N);
            }

            return normalizedI * eta + normalizedN * (eta * cosi - sqrtf(k));
        }

        static Vector3 Reflect(Vector3 I, Vector3 N)
        {
            Vector3 normalizedI = I.Normal();
            Vector3 normalizedN = N.Normal();
            return normalizedI - normalizedN * 2.0f * normalizedI.Dot(normalizedN);
        }
    };
}
