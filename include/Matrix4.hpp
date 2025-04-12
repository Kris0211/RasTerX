#pragma once
#include "Vector4.hpp"

namespace rtx
{
	// Row-major float4x4
	class Matrix4
	{
	public:
		float fields[4][4] = { {0.0f} };

		Matrix4() = default;
		explicit Matrix4(float fields[4][4]);
		explicit Matrix4(float fields[16]);
		Matrix4(const Vector4& row1, const Vector4& row2, const Vector4& row3, const Vector4& row4);
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
		Matrix4 Mul(const Matrix4& mat) const;

		float Det() const;

		static Matrix4 InvertedMatrix(const Matrix4& mat);
		void Invert();

		static Matrix4 TransposedMatrix(const Matrix4& mat);
		void Transpose();

		void SetRow(const int row, const Vector4& newRow);

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
