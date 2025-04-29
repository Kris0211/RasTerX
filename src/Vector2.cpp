#include "../include/Vector2.hpp"

rtx::Vector2::Vector2()
{
	x = 0.f;
	y = 0.f;
}

rtx::Vector2::Vector2(float x, float y) : x(x), y(y)
{
}

rtx::Vector2::Vector2(const Vector2& v) = default;

rtx::Vector2::Vector2(const std::vector<float>& v) : x(v[0]), y(v[1])
{
}

rtx::Vector2::Vector2(float arr[2]) : x(arr[0]), y(arr[1])
{
}

rtx::Vector2 rtx::Vector2::operator*(float f)
{
	return Vector2(x * f, y * f);
}

rtx::Vector2 rtx::Vector2::operator+(Vector2 v)
{
	return Vector2(x + v.x, y + v.y);
}

std::ostream& rtx::operator<<(std::ostream& Os, const Vector2& v)
{
	Os << "[" << v.x << ", " << v.y << "]";
	return Os;
}
