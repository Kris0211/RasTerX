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
		const float b = dir.Dot(oc);
		const float c = oc.Dot(oc) - radius * radius;

		const float d = b * b - a * c;
		if (d < 0) // No intersection
			return false;

		const float d_sqrt = std::sqrtf(d);
		
		float t = (-b - d_sqrt) / a;
		if (std::abs(t) < FLT_EPSILON)
		{
			t = (-b + d_sqrt) / a;
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
