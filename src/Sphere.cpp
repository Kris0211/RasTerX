#include "../include/Sphere.hpp"

#include <sstream>

namespace rtx
{
	bool Sphere::Hit(const Ray& ray, const float min, const float max) const
	{
		const Vector3 oc = ray.origin - this->center;
		const Vector3 dir = ray.direction;

		const float a = Vector3::DotProduct(dir, dir);
		const float b = Vector3::DotProduct(oc, dir);
		const float c = Vector3::DotProduct(oc, oc) - this->radius * this->radius;

		const float d = b * b - a * c;
		if (d > 0)
		{
			const float dsqrt = std::sqrtf(d);
			float tmp = (-b - dsqrt) / a;
			if (tmp < max && tmp > min) return true;

			tmp = (-b + dsqrt) / a;
			if (tmp < max && tmp > min) return true;
		}

		return false;
	}

	std::string Sphere::ToString() const
	{
		std::stringstream ss;
		ss << "Center: " << this->center.ToString() << "\nRadius: " << this->radius;
		return ss.str();
	}
}
