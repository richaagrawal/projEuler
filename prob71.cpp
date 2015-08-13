#include "probs.h"

void prob71()
{
	unsigned const long N = 1000000;
	bool prime = false;
	bool arrP[N];
	isPrimeSieve(arrP, N);
	double f, frac = 0.0f;
	unsigned long nr, dr;
	double lim = 3.0 / 7.0;

	for (unsigned long i = N; i >=1; i--)
	{
		prime = false;
		if (arrP[i - 1])
			prime = true;
		for (unsigned long j = lim * i - 1; j >= 0; j--)
		{
			f = (double)j / i;
			//the number is small than the previously found big number
			if (frac > f)
				break;
			// Both the numbers are even - they definitely would have 2 as a common factor
			if (i % 2 == 0 && j % 2 == 0)
				continue;
			if (prime || gcd(i, j) == 1)
			{
				frac = f;
				nr = j;
				dr = i;
			}
		}
	}
	cout << "Fraction before 3/7 is: " << nr << "/" << dr << endl;
}