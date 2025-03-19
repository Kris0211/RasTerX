#pragma once

#include "Vector3.h"
#include <sstream>

namespace rtx
{
	class Ray
	{
	public:
		Ray() : _origin(Vector3::Zero()) {};
		Ray(Vector3 origin, Vector3 direction) : _origin(origin), _direction(direction) {};
		Ray(Vector3 origin, float dist) : _origin(origin), _distance(dist) {};
		Ray(Vector3 origin, Vector3 direction, float dist) : _origin(origin), _direction(direction), _distance(dist) {};
		Ray(const Ray& r) : 
			_origin(r.GetOrigin()), _direction(r.GetDirection()), 
			_destination(r.GetDestination()), _distance(r.GetDistance()) 
		{};

		Vector3 GetOrigin() const { return _origin; };
		void SetOrigin(const Vector3 o) { _origin = o; };
		
		Vector3 GetDestination() const { return _destination; };
		void SetDestination(const Vector3 d) { _destination = d; };

		Vector3 GetDirection() const { return _direction; };
		void SetDirection(const Vector3 d) { _direction = d; ; }

		float GetDistance() const { return _distance; };
		void SetDistance(const float d) { _distance = d; };
		
		std::string ToString() const 
		{
			std::stringstream ss;
			ss << "Origin: " << this->_origin.ToString() << "\nDestination: " << this->_destination.ToString()
				<< "\nDirection: " << this->_direction.ToString() << "\nDistance: " << this->_distance;
			return ss.str();
		};
	
	private:
		Vector3 _origin;
		Vector3 _destination;
		Vector3 _direction;
		float _distance = 1.f;
	};
}