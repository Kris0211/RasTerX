#pragma once
#include "Vector3.hpp"

namespace rtx
{
	class Ray;

	class Plane
	{
	public:
		Vector3 n;
		Vector3 p;

		Plane() = default;
		Plane(const Vector3& p, const Vector3& n);
		Plane(float a, float b, float c, float d);
		Plane(const Plane& plane);

		bool Intersects(const Ray& ray, Vector3& ref_IntersectionPoint) const;
	};
}
