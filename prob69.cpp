#include "probs.h"

// Totient's formula: phi(n) = n*product(1-1/p) where p are distinct primes
void prob69()
{
	double phi = 0;
	unsigned long maxI = 0;
	double maxPhi = 0;
	const unsigned int N = 1000000;
	bool arr[N];
	isPrimeSieve(arr, N);
	unsigned long no, j;
	unsigned long lastj = 0;
	for (unsigned long i = 2; i < N; i++)
	{
		if (arr[i-1])
			continue;
		phi = i;
		no = i;
		j = 2;
		lastj = 0;
		while (no > 1)
		{
			// Factorise all prime numbers
			if (no % j == 0)
			{
				no /= j;
				if (lastj == 0)
				{
					phi = phi * (1 - (1 / (double)j));
					lastj = j;
				}
			}
			// Only a prime number is left
			else if (arr[no - 1])
			{
				phi = phi * (1 - (1 / (double)no));
				break;
			}
			else
			{
				j++;
				lastj = 0;
			}
		}
		if (i / phi > maxPhi)
		{
			maxPhi = i / phi;
			maxI = i;
		}
	}
	cout << "\nMax n/phi for n = " << maxI << endl;
}