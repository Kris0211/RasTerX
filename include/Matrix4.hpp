#pragma once
#include "Vector4.hpp"

namespace rtx
{
	class Matrix4
	{
	public:
		float fields[4][4] = { {0.0f} };

		Matrix4() = default;
		explicit Matrix4(float fields[4][4]);
		explicit Matrix4(float fields[16]);
		Matrix4(const Matrix4& mat);
		~Matrix4() = default;

		static Matrix4 Identity();
		void LoadIdentity();

		Matrix4 operator+(const Matrix4& mat);
		Matrix4 operator-(const Matrix4& mat);
		Matrix4 operator*(float f);
		Matrix4 operator*(const Matrix4& mat);
		Vector4 operator*(const Vector4& vec) const;
		Vector3 operator*(const Vector3& vec);

		void Add(const Matrix4& mat);
		void Sub(const Matrix4& mat);
		void Mul(float f);
		Matrix4 Mul(const Matrix4& mat);

		float Det() const;

		static Matrix4 InvertedMatrix(const Matrix4& mat);
		void Invert();

		static Matrix4 TransposedMatrix(const Matrix4& mat);
		void Transpose();

		void SetTranslation(const Vector3& trans);

		void SetScale(const Vector3& scale);
		void SetScale(float uniformScale);

		void SetRotationAxis(double angle, const Vector3& axis);
		void SetRotationX(double angle);
		void SetRotationY(double angle);
		void SetRotationZ(double angle);

		void PrintMatrix() const;
	};
}
