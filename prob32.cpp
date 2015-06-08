#pragma once

#include "probs.h"

bool isPandigital(long a, long b, long c)
{
	int digits[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int rem; 
	while (a > 0)
	{
		rem = a % 10 - 1;
		if (rem == -1 || digits[rem] == 1)
			return false;
		digits[rem]++;
		a /= 10;
	}
	while (b > 0)
	{
		rem = b % 10 - 1;
		if (rem == -1 || digits[rem] == 1)
			return false;
		digits[rem]++;
		b /= 10;
	}
	while (c > 0)
	{
		rem = c % 10 - 1;
		if (rem == -1 || digits[rem] == 1)
			return false;
		digits[rem]++;
		c /= 10;
	}
	for (int i = 0; i < 9; i++)
	{
		if (digits[i] != 1)
			return false;
	}
	return true;
}

void prob32()
{
	vector<int> pandigitalNos;
	long sum = 0;
	int prod = 0;

	for (long i = 2; i < 9876; i++)
	{
		for (long j = 3; j < i; j++)
		{
			prod = i * j;
			
			if (isPandigital(i, j, prod))
			{
				if (find(pandigitalNos.begin(), pandigitalNos.end(), i*j) == pandigitalNos.end())
				{
					pandigitalNos.push_back(prod);
					sum += prod;
				}
			}
		}
	}

	cout << "Sum of pandigital products: " << sum << endl;
}