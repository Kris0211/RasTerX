#pragma once

#include <string>
#include <vector>
#include <ostream>

namespace rtx
{
	class Vector2
	{
	public:
		float x, y;

		Vector2();
		Vector2(float x, float y);
		Vector2(const Vector2& v);
		explicit Vector2(const std::vector<float>& v);
		explicit Vector2(float arr[2]);

		friend std::ostream& operator<<(std::ostream& Os, const Vector2& v);

		Vector2 operator*(float f);
		Vector2 operator+(Vector2 v);

		static Vector2 Zero() { return {0.f, 0.f}; }
	};
}
