#pragma once

#include "Vector3.hpp"
#include "Ray.hpp"

namespace rtx
{
	class Sphere
	{
	public:
		Vector3 center;
		float radius;

		Sphere() : center(Vector3::Zero()), radius(1.f) {};
		explicit Sphere(const float r) : center(Vector3::Zero()), radius(r) {}
		explicit Sphere(const Vector3& v) : center(v), radius(1.f) {}
		Sphere(const Vector3& v, const float r) : center(v), radius(r) {}
		Sphere(const Sphere& s) = default;

		bool Intersects(const Ray& ray, Vector3& ref_IntersectionPoint) const;

		std::string ToString() const;
	};
}
