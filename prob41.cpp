#pragma once
#include "probs.h"

void prob41()
{
	// 8 and 9 digit pandigital numbers are not prime
	// 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 = 45 -> divisible by 3 - hence composite
	// 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 = 36 -> divisible by 3 - hence composite
	long no = 7654321;
	for (; no > 0; no -= 2)
	{
		if (!isPandigital(no))
			continue;
		if (isPrime(no))
			break;
	}
	cout << "Pandigital no: " << no << endl;
}