#pragma once
#include "Vector3.hpp"
#include "Vector4.hpp"

namespace rtx
{
	class Quaternion
	{
	public:
		float re;
		Vector3 im;

		Quaternion();
		Quaternion(float a, float i, float j, float k);
		Quaternion(const float f[4]);
		Quaternion(const float a, const Vector3& v);
		Quaternion(const Vector4& v);
		~Quaternion() = default;

		// Convert angle-axis rotation to quat
		static Quaternion RotationQuaternion(double angle, const Vector3& axis);

		std::string ToString() const;

		Quaternion operator+(const Quaternion& q) const;
		Quaternion operator-(const Quaternion& q) const;
		Quaternion operator*(const Quaternion& q) const;
		Quaternion operator/(const Quaternion& q) const;

		void operator+=(const Quaternion& q);
		void operator-=(const Quaternion& q);
		void operator*=(const Quaternion& q);
		void operator/=(const Quaternion& q);

		void Add(const Quaternion& q);
		void Sub(const Quaternion& q);
		void Mul(const Quaternion& q);
		void Div(const Quaternion& q);

		float Dot(const Quaternion& q) const;
		static float DotProduct(const Quaternion& q1, const Quaternion& q2);

		float Re() const;
		Vector3 Im() const;

		void Inverted();
		static Quaternion Invert(const Quaternion& q);

		void Conjugate();
		static Quaternion GetConjugate(const Quaternion& q);

		float Magnitude() const;
		static float GetMagnitude(const Quaternion& q);
	};
}
