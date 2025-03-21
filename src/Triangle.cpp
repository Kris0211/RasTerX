#include "../include/Triangle.hpp"
#include "../include/Ray.hpp"

constexpr float EPSILON = 1e-6f;

namespace rtx
{
	Triangle::Triangle(const Vector3& v1, const Vector3& v2, const Vector3& v3)
	{
		this->vertices[0] = v1;
		this->vertices[1] = v2;
		this->vertices[2] = v3;
	}

	Triangle::Triangle(const Vector3& v1, const Vector3& v2, const Vector3& v3, 
		const Vector3& n1, const Vector3& n2, const Vector3& n3)
	{
		this->vertices[0] = v1;
		this->vertices[1] = v2;
		this->vertices[2] = v3;
		this->normals[0] = n1;
		this->normals[1] = n2;
		this->normals[2] = n3;
	}

	bool Triangle::Intersects(const Ray& ray, Vector3& ref_IntersectionPoint) const
	{
		Vector3 AB = vertices[1] - vertices[0];
		Vector3 AC = vertices[2] - vertices[0];
		Vector3 normal = Vector3::CrossProduct(AB, AC);

		float dot = Vector3::DotProduct(normal, ray.direction);
		if (fabs(dot) < EPSILON)
		{
			return false;
		}

		float t = Vector3::DotProduct(normal, vertices[0] - ray.origin) / dot;
		if (t < 0.f)
		{
			return false;
		}

		ref_IntersectionPoint = ray.origin + ray.direction * t;

		Vector3 AP = ref_IntersectionPoint - vertices[0];
		Vector3 BP = ref_IntersectionPoint - vertices[1];
		Vector3 CP = ref_IntersectionPoint - vertices[2];

		Vector3 v1 = Vector3::CrossProduct(AB, AP);
		Vector3 v2 = Vector3::CrossProduct(AC, BP);
		Vector3 v3 = Vector3::CrossProduct((vertices[1] - vertices[2]), CP);

		if (Vector3::DotProduct(v1, normal) >= 0.f &&
			Vector3::DotProduct(v2, normal) >= 0.f &&
			Vector3::DotProduct(v3, normal) >= 0.f)
		{
			return true;
		}

		return false;
	}
}
