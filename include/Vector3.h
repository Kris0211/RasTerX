#pragma once

#include <string>
#include <vector>

namespace rtx
{
	class Vector3
	{
	public:
		float x, y, z;

		Vector3();
		Vector3(float x, float y, float z);
		Vector3(const Vector3& v);
		Vector3(std::vector<float> v);
		Vector3(float arr[3]);

		std::string ToString() const;

		Vector3& operator=(const Vector3& v);

		bool operator==(const Vector3& v) const;
		bool operator!=(const Vector3& v) const;

		Vector3 operator+(const Vector3& v) const;
		Vector3 operator-(const Vector3& v) const;
		void operator+=(const Vector3& v);
		void operator-=(const Vector3& v);

		Vector3 operator+(float f) const;
		Vector3 operator-(float f) const;
		void operator+=(float f);
		void operator-=(float f);

		Vector3 operator*(float f) const;
		Vector3 operator/(float f) const;
		void operator*=(float f);
		void operator/=(float f);

		Vector3 operator*(const Vector3& v) const;
		Vector3 operator/(const Vector3& v) const;

		Vector3 operator-();

		inline void Add(const Vector3& v);
		inline void Sub(const Vector3& v);
		inline void Mul(float f);
		inline void Div(float f);

		inline float Length() const;
		inline void Normalize();
		Vector3 Normal() const;
		bool IsNear(const Vector3& vec, float tolerance) const;

		static Vector3 Dot(const Vector3& v1, const Vector3& v2);
		static float DotProduct(const Vector3& v1, const Vector3& v2);
		static Vector3 CrossProduct(const Vector3& v1, const Vector3& v2);
		static float AngleBetween(const Vector3& v1, const Vector3& v2);

		static Vector3 Min(Vector3 a, Vector3 b);
		static Vector3 Max(Vector3 a, Vector3 b);

		static Vector3 Zero() { return Vector3(0.f, 0.f, 0.f); };
	};
}
