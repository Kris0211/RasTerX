#pragma once
#include "Vector3.hpp"

namespace rtx 
{
	class Ray;

	class Triangle 
	{
	public:
		Triangle() = default;
		Triangle(const Vector3& v1, const Vector3& v2, const Vector3& v3);
		Triangle(const Vector3& v1, const Vector3& v2, const Vector3& v3,
			const Vector3& n1, const Vector3& n2, const Vector3& n3);

		bool Intersects(const Ray& ray, Vector3& ref_IntersectionPoint) const;

		Vector3 GetVertA() const { return vertices[0]; }
		Vector3 GetVertB() const { return vertices[1]; }
		Vector3 GetVertC() const { return vertices[2]; }

	private:
		Vector3 vertices[3];
		Vector3 normals[3];
	};
}
