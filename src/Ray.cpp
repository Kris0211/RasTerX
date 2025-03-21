#include "../include/Ray.hpp"
namespace rtx
{
	Ray::Ray() : origin(Vector3::Zero()), distance(0.f)
	{}

	Ray::Ray(const Vector3& origin, const Vector3& direction, const float distance) 
		: origin(origin), direction(direction), distance(distance)
	{}

	std::string Ray::ToString() const
	{
		std::stringstream ss;
		ss << "Origin: " << this->origin.ToString() << "\nDirection: " << this->direction.ToString()
			<< "\nDestination: " << this->destination.ToString() << "\nDistance: " << this->distance;
		return ss.str();
	}
}
