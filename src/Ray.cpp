#include "../include/Ray.hpp"
namespace rtx
{
	Ray::Ray() 
		: origin(Vector3::Zero()), direction(Vector3::Zero()), distance(0.f)
	{}

	Ray::Ray(const Vector3& origin, const Vector3& direction, const float distance) 
		: origin(origin), direction(direction.Normal()), distance(distance)
	{}

	Vector3 Ray::PointAt(const float t) const
	{
		return origin + direction * t;
	}

	std::string Ray::ToString() const
	{
		std::stringstream ss;
		ss << "{\nOrigin: " << this->origin.ToString() 
			<< "\nDirection: " << this->direction.ToString()
			<< "\nDistance: " << this->distance << "\n}";
		return ss.str();
	}
}
