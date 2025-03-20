#include "../include/Vector4.hpp"
#include <cmath>
#include <stdexcept>
#include <sstream>

namespace rtx 
{
	Vector4::Vector4() : x(0), y(0), z(0), w(0) {}

	Vector4::Vector4(const float x, const float y, const float z) : x(x), y(y), z(z), w(0) {}

	Vector4::Vector4(const float x, const float y, const float z, const float w) : x(x), y(y), z(z), w(w) {}

	Vector4::Vector4(const Vector4& v) : x(v.x), y(v.y), z(v.z), w(v.w) {}

	Vector4::Vector4(const Vector3& v) : x(v.x), y(v.y), z(v.z), w(0) {}

	Vector4::Vector4(const Vector3& v, const float w) : x(v.x), y(v.y), z(v.z), w(w) {}

	std::string Vector4::ToString() const
	{
		std::stringstream ss;
		ss << "[" << this->x << ", " << this->y << ", " << this->z << ", " << this->w << "]";
		return ss.str();
	}

	Vector4& Vector4::operator=(const Vector4& v) = default;

	Vector4 Vector4::operator+(const Vector4& v) const
	{
		return { x + v.x, y + v.y, z + v.z, w + v.w };
	}

	Vector4 Vector4::operator-(const Vector4& v) const
	{
		return { x - v.x, y - v.y, z - v.z, w - v.w };
	}

	void Vector4::operator+=(const Vector4& v)
	{
		this->x += v.x;
		this->y += v.y;
		this->z += v.z;
		this->w += v.w;
	}

	void Vector4::operator-=(const Vector4& v)
	{
		this->x -= v.x;
		this->y -= v.y;
		this->z -= v.z;
		this->w -= v.w;
	}

	Vector4 Vector4::operator*(const float f) const
	{
		return { x * f, y * f, z * f, w * f };
	}

	Vector4 Vector4::operator/(float f) const
	{
		if (f == 0)
		{
			throw std::logic_error("Math error: Cannot divide by zero\n");
		}

		f = 1 / f;
		return { x * f, y * f, z * f, w * f };
		
	}

	void Vector4::operator*=(const float f)
	{
		x *= f;
		y *= f;
		z *= f;
		w *= f;
	}

	void Vector4::operator/=(float f)
	{
		if (f == 0)
		{
			throw std::logic_error("Math error: Cannot divide by zero\n");
		}
		
		f = 1 / f;
		x *= f;
		y *= f;
		z *= f;
		w *= f;
	}

	void Vector4::Add(const Vector4& v)
	{
		this->x += v.x;
		this->y += v.y;
		this->z += v.z;
		this->w -= v.w;
	}

	void Vector4::Sub(const Vector4& v)
	{
		this->x -= v.x;
		this->y -= v.y;
		this->z -= v.z;
		this->w -= v.w;
	}

	void Vector4::Mul(const float f)
	{
		this->x *= f;
		this->y *= f;
		this->z *= f;
		this->w *= f;
	}

	void Vector4::Div(float f)
	{
		if (f == 0)
		{
			throw std::logic_error("Math error: Cannot divide by zero\n");
		}
		
		f = 1 / f;
		this->x *= f;
		this->y *= f;
		this->z *= f;
		this->w *= f;
	}

	float Vector4::Length() const
	{
		return sqrt(
			this->x * this->x +
			this->y * this->y +
			this->z * this->z +
			this->w * this->w);
	}

	void Vector4::Normalize()
	{
		const float n = this->Length();
		if (n != 0) this->Div(n);
		else throw std::logic_error("Math error: Cannot divide by zero\n");
	}
}
