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
		Vector3 destination;
		float distance;

		Ray();
		Ray(const Vector3& origin, const Vector3& destination);
		Ray(const Vector3& origin, const Vector3& direction, const float distance);
		Ray(const Ray& r) = default;

		std::string ToString() const;
	};
}
