#include "../include/Matrix3.hpp"

#include <cstdio>
#include <iostream>

namespace rtx
{
	float Matrix3::Det() const
	{
		float ret = 0;

		for (int i = 0; i < 3; i++)
		{
			float tempAdd = 1;
			float tempSub = 1;

			for (int k = 0; k < 3; k++)
			{
				tempAdd *= fields[k][(i + k) % 3];
				tempSub *= fields[2 - k][(i + k) % 3];
			}

			ret += tempAdd;
			ret -= tempSub;
		}

		return ret;
	}

	void Matrix3::PrintMatrix() const
	{
		for (int i = 0; i < 3; i++)
		{
			for (int k = 0; k < 3; k++)
			{
				printf("[%f]", fields[i][k]);
			}
			printf("\n");
		}
	}
}
