#pragma once

namespace rtx
{
	class Matrix3
	{
	public:

		float fields[3][3] = { {0.0f} };

		Matrix3() = default;

		float Det() const;
		void PrintMatrix() const;
	};
}
