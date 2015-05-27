#pragma once
#include "probs.h"

void prob30()
{
	int num = 0;
	int rem = 0;
	int sumPowerFive = 0;
	long long addSumPowerFive = 0;
	for (int i = 1; i < 1000000; i++)
	{
		num = i;
		rem = 10;
		sumPowerFive = 0;
		while (num > 9)
		{
			rem = num % 10;
			num = num / 10;
			sumPowerFive += (int)pow(rem, 5);
		}
		sumPowerFive += (int)pow(num, 5);
		if (sumPowerFive == i)
		{
			addSumPowerFive += sumPowerFive;
		}
	}
	printf("Sum of all power 5 digits: %d", addSumPowerFive - 1);
}