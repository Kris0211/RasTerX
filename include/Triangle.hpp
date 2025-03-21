#pragma once
#include "Vector3.hpp"

namespace rtx 
{
	class Ray;

	class Triangle 
	{
	public:
		Vector3 vertices[3];
		Vector3 normals[3];

		Triangle() = default;
		Triangle(const Vector3& v1, const Vector3& v2, const Vector3& v3);
		Triangle(const Vector3& v1, const Vector3& v2, const Vector3& v3,
			const Vector3& n1, const Vector3& n2, const Vector3& n3);

		bool Intersects(const Ray& ray, Vector3& outIntersectionPoint) const;
	};
}
