#pragma once
#include "probs.h"

void prob27()
{
	int lim = 999;
	int max = 0;
	int a, b;
	int maxA, maxB;
	for (a = -lim; a <= lim; a += 2)
	{
		for (b = -lim; b <= lim; b += 2)
		{
			bool prime = true;
			int no = 0;
			int n = 0;
			while (prime)
			{
				no = abs(n * n + a * n + b);
				prime = isPrime(no);
				n++;
			}
			n -= 2;
			if (n >= max)
			{
				max = n;
				maxA = a;
				maxB = b;
			}
		}
	}
	std::cout << "Product of coefficients: " << maxA * maxB << endl;
}