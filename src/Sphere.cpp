#include "../include/Sphere.h"

#include <cmath>
#include <sstream>

namespace rtx
{
	bool Sphere::Hit(const Ray& ray, float min, float max) const
	{
		const Vector3 oc = ray.GetOrigin() - this->_center;
		const Vector3 dir = ray.GetDirection();

		const float a = Vector3::DotProduct(dir, dir);
		const float b = Vector3::DotProduct(oc, dir);
		const float c = Vector3::DotProduct(oc, oc) - this->_radius * this->_radius;

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
		ss << "Center: " << this->_center.ToString() << "\nRadius: " << this->_radius;
		return ss.str();
	}
}
