#include "probs.h"

void prob357()
{
	const unsigned long long N = 100000000;

	// Had issues with allocating huge array - http://stackoverflow.com/questions/216259/is-there-a-max-array-length-limit-in-c
	bool* primeArr = new bool[N];
	
	isPrimeSieve(primeArr, N);
	unsigned long long div;
	bool pgn = false;
	unsigned long long sum = 1;

	// Has to be even except for 1
	// Because odd + 1 = even and even is not prime
	for (unsigned long long i = 2; i < N; i += 2)
	{
		// Quick check - check if number + 1 is prime as (number,1) are divisors
		if (!primeArr[i + 1 - 1])
			continue;
		pgn = true;
		for (unsigned long long j = 2; j <= sqrt(i); j++)
		{
			if (i % j == 0)
			{
				div = i / j + j;
				if (!primeArr[div - 1])
				{
					pgn = false;
					break;
				}
			}
		}
		if (pgn == true)
			sum += i;
	}
	cout << "Sum of prime generating numbers: " << sum << endl;
}