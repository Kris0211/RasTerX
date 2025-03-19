#pragma once

#include "Vector3.h"
#include "Ray.h"

namespace rtx
{
	class Sphere
	{
	public:
		Sphere() : _center(Vector3::Zero()), _radius(1.f) {};
		Sphere(float r) : _center(Vector3::Zero()), _radius(r) {};
		Sphere(Vector3 v) : _center(v), _radius(1.f) {};
		Sphere(Vector3 v, float r) : _center(v), _radius(r) {};
		Sphere(const Sphere& s) : _center(s.GetCenter()), _radius(s.GetRadius()) {};

		bool Hit(const Ray& ray, float min, float max) const;

		Vector3 GetCenter() const { return _center; };
		void SetCenter(Vector3 v) { _center = v; };
		float GetRadius() const { return _radius; };
		void SetRadius(const float r) { _radius = r; };

		std::string ToString() const;

	private:
		Vector3 _center;
		float _radius;
	};
}
