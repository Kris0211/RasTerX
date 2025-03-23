#include "../include/Ray.hpp"
namespace rtx
{
	Ray::Ray() : origin(Vector3::Zero()), direction(Vector3::Zero()), distance(0.f)
	{}

	Ray::Ray(const Vector3& origin, const Vector3& destination)
		: origin(origin), destination(destination)
	{
		direction = (destination - origin).Normal();
		//distance = (destination - origin).Length();
		distance = FLT_MAX;
	}

	Ray::Ray(const Vector3& origin, const Vector3& direction, const float distance) 
		: origin(origin), direction(direction), distance(distance)
	{
		destination = origin + this->direction * distance;
	}

	std::string Ray::ToString() const
	{
		std::stringstream ss;
		ss << "{\nOrigin: " << this->origin.ToString() << "\nDirection: " << this->direction.ToString()
			<< "\nDestination: " << this->destination.ToString() << "\nDistance: " << this->distance << "\n}";
		return ss.str();
	}
}
