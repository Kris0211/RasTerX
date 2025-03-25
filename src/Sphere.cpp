#include "../include/Sphere.hpp"

#include <sstream>
#include <iostream>

namespace rtx
{
	bool Sphere::Intersects(const Ray& ray, Vector3& ref_IntersectionPoint) const
	{
		const Vector3 oc = ray.origin - center;
		const Vector3 dir = ray.direction;

		const float a = dir.Dot(dir);
		const float b = oc.Dot(dir) * 2.f;
		const float c = oc.Dot(oc) - radius * radius;

		const float d = b * b - 4 * a * c;
		if (d < 0) // No intersection
			return false;

		const float d_sqrt = std::sqrtf(d);
		
		float t = (-b - d_sqrt) / (2.f * a);
		if (t < FLT_EPSILON)
		{
			t = (-b + d_sqrt) / (2.f * a);
		}

		if (t <= 0) // Intersections are behind the raycast
			return false;

		ref_IntersectionPoint = ray.origin + ray.direction * t;
		return true;
	}

	std::string Sphere::ToString() const
	{
		std::stringstream ss;
		ss << "Center: " << this->center.ToString() << "\nRadius: " << this->radius;
		return ss.str();
	}
}
