#include "../include/Quaternion.hpp"
#include "../include/Vector4.hpp"

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

	Vector3 Quaternion::RotateVectorByQuaternion(const Vector3& v)
	{
		// Convert vector to a pure quaternion
		Quaternion p(0, v);
		Quaternion q = GetUnitNormQuaternion(*this);
		Quaternion rotatedVector = q * p * q.InvertQuaternion(q);

		return rotatedVector.im;
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

	Quaternion Quaternion::operator*(const float& f) const
	{
		return Quaternion(
			re * f,
			im * f
		);
	}

	Quaternion Quaternion::operator/(const float& f) const
	{
		if (f != 0)
		{
			return Quaternion(
				re / f,
				im / f
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

	Quaternion Quaternion::InvertQuaternion(const Quaternion& q)
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

	void Quaternion::Normalize()
	{
		if (Magnitude() != 0)
		{
			float norm = 1.f / Magnitude();

			re *= norm;
			im *= norm;
		}
	}

	void Quaternion::UnitNormQuaternion()
	{
		float angle = re;
		im.Normalize();
		re = cosf(angle * 0.5);
		im = im * sinf(angle * 0.5);
	}

	Quaternion Quaternion::GetUnitNormQuaternion(const Quaternion& q)
	{
		return Quaternion(cosf(q.re*0.5), q.im.Normal() * sinf(q.re * 0.5));
	}


	Quaternion Quaternion::EulerToQuaternion(float roll, float pitch, float yaw)
	{
		float cr = cos(roll * 0.5f);
		float sr = sin(roll * 0.5f);
		float cp = cos(pitch * 0.5f);
		float sp = sin(pitch * 0.5f);
		float cy = cos(yaw * 0.5f);
		float sy = sin(yaw * 0.5f);

		float w = cr * cp * cy + sr * sp * sy;
		float x = sr * cp * cy - cr * sp * sy;
		float y = cr * sp * cy + sr * cp * sy;
		float z = cr * cp * sy - sr * sp * cy;
		
		return Quaternion(w, Vector3(x, y, z));
	}

	Quaternion Quaternion::EulerToQuaternion(const EulerAngles& ea)
	{
		return Quaternion::EulerToQuaternion(ea.roll, ea.pitch, ea.yaw);
	}

	EulerAngles Quaternion::QuaternionToEuler(const Quaternion& q)
	{
		EulerAngles angles = {};

		const Vector3 q_im = q.Im();

		float sinr_cosp = 2 * (q.Re() * q_im.x + q_im.y * q_im.z);
		float cosr_cosp = 1 - 2 * (q_im.x * q_im.x + q_im.y * q_im.y);
		angles.roll = std::atan2f(sinr_cosp, cosr_cosp);

		float sinp = std::sqrt(1 + 2 * (q.Re() * q_im.y - q_im.x * q_im.z));
		float cosp = std::sqrt(1 - 2 * (q.Re() * q_im.y - q_im.x * q_im.z));
		angles.pitch = 2 * std::atan2f(sinp, cosp) - PI / 2;

		float siny_cosp = 2 * (q.Re() * q_im.z + q_im.x * q_im.y);
		float cosy_cosp = 1 - 2 * (q_im.y * q_im.y + q_im.z * q_im.z);
		angles.yaw = std::atan2f(siny_cosp, cosy_cosp);

		return angles;
	}
}
