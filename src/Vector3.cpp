#include "../include/Vector3.hpp"

#include <cmath>
#include <stdexcept>
#include <sstream>

namespace rtx
{
	Vector3::Vector3() : x(0), y(0), z(0) {}

	Vector3::Vector3(const float x, const float y, const float z) : x(x), y(y), z(z) {}

	Vector3::Vector3(const Vector3& v) = default;

	Vector3::Vector3(const std::vector<float>& v) : x(v[0]), y(v[1]), z(v[2]) {}

	Vector3::Vector3(float arr[3]) : x(arr[0]), y(arr[1]), z(arr[2]) {}

	std::string Vector3::ToString() const
	{
		std::stringstream ss;
		ss << "[" << this->x << ", " << this->y << ", " << this->z << "]";
		return ss.str();
	}

	Vector3& Vector3::operator=(const Vector3& v) = default;

	bool Vector3::operator==(const Vector3& v) const
	{
		return x == v.x && y == v.y && z == v.z;
	}

	bool Vector3::operator!=(const Vector3& v) const
	{
		return x != v.x || y != v.y || z != v.z;
	}

	Vector3 Vector3::operator+(const Vector3& v) const
	{
		return { x + v.x, y + v.y, z + v.z };
	}

	Vector3 Vector3::operator-(const Vector3& v) const
	{
		return { x - v.x, y - v.y, z - v.z };
	}

	void Vector3::operator+=(const Vector3& v)
	{
		this->x += v.x;
		this->y += v.y;
		this->z += v.z;
	}

	void Vector3::operator-=(const Vector3& v)
	{
		this->x -= v.x;
		this->y -= v.y;
		this->z -= v.z;
	}

	Vector3 Vector3::operator+(const float f) const
	{
		return { x + f, y + f, z + f };
	}

	Vector3 Vector3::operator-(const float f) const
	{
		return { x - f, y - f, z - f };
	}


	void Vector3::operator+=(const float f)
	{
		this->x += f;
		this->y += f;
		this->z += f;
	}

	void Vector3::operator-=(const float f)
	{
		this->x -= f;
		this->y -= f;
		this->z -= f;
	}

	Vector3 Vector3::operator*(const float f) const
	{
		return { x * f, y * f, z * f };
	}

	Vector3 Vector3::operator/(float f) const
	{
		if (f == 0.0f)
		{
			throw std::logic_error("Math error: Cannot divide by zero\n");
		}

		f = 1 / f;
		return { x * f, y * f, z * f };
	}

	void Vector3::operator*=(const float f)
	{
		x *= f;
		y *= f;
		z *= f;
	}

	void Vector3::operator/=(float f)
	{
		if (f == 0.0f)
		{
			throw std::logic_error("Math error: Cannot divide by zero\n");	
		}

		f = 1 / f;
		x *= f;
		y *= f;
		z *= f;
	}

	Vector3 Vector3::operator*(const Vector3& v) const
	{
		return { this->x * v.x, this->y * v.y, this->z * v.z };
	}

	Vector3 Vector3::operator/(const Vector3& v) const
	{
		return { this->x / v.x, this->y / v.y, this->z / v.z };
	}

	Vector3 Vector3::operator-() const
	{
		Vector3 vec;
		vec.x = -this->x;
		vec.y = -this->y;
		vec.z = -this->z;
		return vec;
	}

	float& Vector3::operator[](int index)
	{
		switch (index)
		{
			case 0: return x;
			case 1: return y;
			case 2: return z;
			default: throw std::out_of_range("Vector3: index out of range");
		}
	}

	const float& Vector3::operator[](int index) const
	{
		switch (index)
		{
			case 0: return x;
			case 1: return y;
			case 2: return z;
			default: throw std::out_of_range("Vector3: index out of range");
		}
	}

	void Vector3::Add(const Vector3& v)
	{
		this->x += v.x;
		this->y += v.y;
		this->z += v.z;
	}

	void Vector3::Sub(const Vector3& v)
	{
		this->x -= v.x;
		this->y -= v.y;
		this->z -= v.z;
	}

	void Vector3::Mul(const float f)
	{
		this->x *= f;
		this->y *= f;
		this->z *= f;
	}

	void Vector3::Div(float f)
	{
		if (f == 0)
		{
			throw std::logic_error("Math error: Cannot divide by zero\n");
		}

		f = 1 / f;
		this->x *= f;
		this->y *= f;
		this->z *= f;
	}

	float Vector3::Length() const
	{
		return sqrt(
			this->x * this->x +
			this->y * this->y +
			this->z * this->z);
	}

	void Vector3::Normalize()
	{
		const float n = this->Length();
		if (n != 0.0f) this->Div(n);
		else throw std::logic_error("Math error: Cannot divide by zero\n");
	}

	Vector3 Vector3::Normal() const
	{
		const float len = this->Length();
		if (len == 0.0f) return { 0.f, 0.f, 0.f };
		return *this / len;
	}

	bool Vector3::IsNear(const Vector3& vec, const float tolerance) const
	{
		return std::abs(this->Length() - vec.Length()) < tolerance;
	}

	float Vector3::Dot(const Vector3& v) const
	{
		return (this->x * v.x) + (this->y * v.y) + (this->z * v.z);
	}

	float Vector3::DotProduct(const Vector3& v1, const Vector3& v2)
	{
		return (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z);
	}

	Vector3 Vector3::Cross(const Vector3& v) const
	{
		return {
			this->y * v.z - this->z * v.y,
			this->z * v.x - this->x * v.z,
			this->x * v.y - this->y * v.x
		};
	}

	Vector3 Vector3::CrossProduct(const Vector3& v1, const Vector3& v2)
	{
		return {
			v1.y * v2.z - v1.z * v2.y,
			v1.z * v2.x - v1.x * v2.z,
			v1.x * v2.y - v1.y * v2.x
		};
	}

	float Vector3::AngleBetween(const Vector3& v1, const Vector3& v2)
	{
		return acos(DotProduct(v1, v2) / (v1.Length() * v2.Length()));
	}

	Vector3 Vector3::Min(const Vector3& a, const Vector3& b) 
	{
		Vector3 result;
		result.x = std::min(a.x, b.x);
		result.y = std::min(a.y, b.y);
		result.z = std::min(a.z, b.z);
		return result;
	}

	Vector3 Vector3::Max(const Vector3& a, const Vector3& b) 
	{
		Vector3 result;
		result.x = std::max(a.x, b.x);
		result.y = std::max(a.y, b.y);
		result.z = std::max(a.z, b.z);
		return result;
	}
}
