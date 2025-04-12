#pragma once

#include "Vector3.hpp"

namespace rtx 
{
	class Vector4 
	{
	public:
		float x, y, z, w;

		Vector4();
		Vector4(float x, float y, float z);
		Vector4(float x, float y, float z, float w);
		Vector4(const Vector4& v);
		Vector4(const Vector3& v);
		Vector4(const Vector3& v, float w);

		std::string ToString() const;

		Vector4& operator=(const Vector4& v);

		Vector4 operator+(const Vector4& v) const;
		Vector4 operator-(const Vector4& v) const;
		void operator+=(const Vector4& v);
		void operator-=(const Vector4& v);

		Vector4 operator*(float f) const;
		Vector4 operator/(float f) const;
		void operator*=(float f);
		void operator/=(float f);

		float& operator[](int index);
		const float& operator[](int index) const;

		void Add(const Vector4& v);
		void Sub(const Vector4& v);
		void Mul(float f);
		void Div(float f);

		float Length() const;
		void Normalize();

		static Vector4 Zero() { return { 0.f, 0.f, 0.f, 0.f }; }
	};
}
