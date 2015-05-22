#pragma once
#include "probs.h"

void prob48()
{
	long long sum = 0;
	long long p = 1;
	for (int i = 1; i < 1001; i++)
	{
		p = 1;
		for (int j = 0; j < i; j++)
		{
			p *= i;
			p %= 100000000000;
		}
		sum += p;
		sum = sum % 1000000000000;
		
	}

	cout << "Sum of self powers: " << sum << endl;
}