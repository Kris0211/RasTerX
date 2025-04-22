#pragma once

#include "Vector3.hpp"
#include <sstream>

namespace rtx
{
	class Ray
	{
	public:
		Vector3 origin;
		Vector3 direction;
		float distance;

		Ray();
		Ray(const Vector3& origin, const Vector3& direction, const float distance = FLT_MAX);
		Ray(const Ray& r) = default;

		Vector3 PointAt(const float t) const;

		std::string ToString() const;
	};
}
