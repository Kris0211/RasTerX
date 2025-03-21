#include "../include/Plane.hpp"
#include "../include/Ray.hpp"

namespace rtx
{
    Plane::Plane(const Vector3& n, const Vector3& p)
    {
        this->n = n.Normal();
        this->p = p;
    }

    Plane::Plane(float a, float b, float c, float d)
    {
        this->n = { a, b, c };
        this->n.Normalize();

        if (c != 0) 
        {
            this->p = { 0, 0, -d / c };
        }
        else if (b != 0) 
        {
            this->p = { 0, -d / b, c };
        }
    }

    Plane::Plane(const Plane& plane) = default;


    bool Plane::Intersects(const Ray& ray, const float range = 0.f) const
    {
        float d = Vector3::DotProduct(ray.direction, this->n);
        if (d == 0) 
            return false;

        float t = Vector3::DotProduct(this->p - ray.origin, this->n) / d;
        
        if (t >= 0 && (range == 0.f || t < range)) 
            return true;

        return false;
    }
}
