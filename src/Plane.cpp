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

}
