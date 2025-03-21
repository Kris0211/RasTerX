#include "../include/Quaternion.hpp"

#include <sstream>
#include <stdexcept>

namespace rtx
{
	Quaternion::Quaternion() : re(0), im(0, 0, 0) {}

	Quaternion::Quaternion(float a, float i, float j, float k) : re(a), im(i, j, k) {}

	Quaternion::Quaternion(const float f[4]) : re(f[0]), im(f[1], f[2], f[3]) {}

	Quaternion::Quaternion(const float a, const Vector3& v) : re(a), im(v) {}

	Quaternion::Quaternion(const Vector4& v) : re(v.x), im(v.y, v.z, v.w) {}

	Quaternion Quaternion::RotationQuaternion(double angle, const Vector3& axis)
	{
		Vector3 normAxis = axis;
		normAxis.Normalize();
		normAxis *= static_cast<float>(sin(angle * -0.5));
		return Quaternion(static_cast<float>(cos(angle * -0.5)), normAxis);
	}

	std::string Quaternion::ToString() const
	{
		std::stringstream ss;
		ss << "(" << re << ", " << im.x << ", " << im.y << ", " << im.z << ")";
		return ss.str();
	}

	Quaternion Quaternion::operator+(const Quaternion& q) const
	{
		return Quaternion(re + q.re, im + q.im);
	}

	Quaternion Quaternion::operator-(const Quaternion& q) const
	{
		return Quaternion(re - q.re, im - q.im);
	}

	Quaternion Quaternion::operator*(const Quaternion& q) const
	{
		return Quaternion(
			re * q.re - Vector3::DotProduct(im, q.im),
			q.im * re + im * q.re + Vector3::CrossProduct(im, q.im)
		);
	}

	Quaternion Quaternion::operator/(const Quaternion& q) const
	{
		float denominator = q.re * q.re + Vector3::DotProduct(q.im, q.im);
		if (denominator != 0)
		{
			return Quaternion(
				(re * q.re + Vector3::DotProduct(im, q.im)) / denominator,
				(q.im * -re + im * q.re - Vector3::CrossProduct(im, q.im)) / denominator
			);
		}
		else throw std::logic_error("Cannot divide quat!");
	}

	void Quaternion::operator+=(const Quaternion& q)
	{
		re += q.re; im += q.im;
	}

	void Quaternion::operator-=(const Quaternion& q)
	{
		re -= q.re; im -= q.im;
	}

	void Quaternion::operator*=(const Quaternion& q)
	{
		re = re * q.re - Vector3::DotProduct(im, q.im);
		im = q.im * re + im * q.re + Vector3::CrossProduct(im, q.im);
	}

	void Quaternion::operator/=(const Quaternion& q)
	{
		float denominator = q.re * q.re + Vector3::DotProduct(q.im, q.im);
		if (denominator != 0.0f)
		{
			re = (re * q.re + Vector3::DotProduct(im, q.im)) / denominator;
			im = (q.im * -re + im * q.re - Vector3::CrossProduct(im, q.im)) / denominator;
		}
		else throw std::logic_error("Cannot divide quat!");
	}

	void Quaternion::Add(const Quaternion& q)
	{
		*this += q;
	}

	void Quaternion::Sub(const Quaternion& q)
	{
		*this -= q;
	}

	void Quaternion::Mul(const Quaternion& q)
	{
		*this *= q;
	}

	void Quaternion::Div(const Quaternion& q)
	{
		*this /= q;
	}

	float Quaternion::Dot(const Quaternion& q) const
	{
		return this->re * q.re + Vector3::DotProduct(this->im, q.im);
	}

	float Quaternion::DotProduct(const Quaternion& q1, const Quaternion& q2)
	{
		return q1.re * q2.re + Vector3::DotProduct(q1.im, q2.im);
	}

	float Quaternion::Re() const
	{
		return re;
	}

	Vector3 Quaternion::Im() const
	{
		return im;
	}

	void Quaternion::Inverted()
	{
		if (re != 0 && im != Vector3::Zero())
		{
			float invMagSq = 1 / (re * re + im.x * im.x + im.y * im.y + im.z * im.z);
			Conjugate();
			re *= invMagSq;
			im *= invMagSq;
		}
		else throw std::logic_error("Cannot invert quat!");
	}

	Quaternion Quaternion::Invert(const Quaternion& q)
	{
		Quaternion ret = q;
		ret.Inverted();
		return ret;
	}

	void Quaternion::Conjugate()
	{
		im *= -1;
	}

	Quaternion Quaternion::GetConjugate(const Quaternion& q)
	{
		Quaternion ret = q;
		ret.im *= -1;
		return ret;
	}

	float Quaternion::Magnitude() const
	{
		return (float)sqrt(
			re * re +
			im.x * im.x +
			im.y * im.y +
			im.z * im.z
		);
	}

	float Quaternion::GetMagnitude(const Quaternion& q)
	{
		return q.Magnitude();
	}
}