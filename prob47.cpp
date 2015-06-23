#include "probs.h"

void prob47()
{
	vector<int> primes;
	int no = 3;
	primes.push_back(2);
	while (no < 999999)
	{
		if (isPrime(no))
			primes.push_back(no);
		no += 2;
	}

	int firstPrime;
	firstPrime = 0;
	int noFactors = 0;
	int mulFactors;
	int consecPrimes = 0;
	int digits = 4;
	for (int i = 134043; i < 999999; i++)
	{
		if (isPrime(i))
		{
			firstPrime = 0;
			continue;
		}
		noFactors = 0;
		mulFactors = 1;
		for (int j = 0; j < primes.size(); j++)
		{
			if (i % primes[j] == 0)
			{
				noFactors++;
				mulFactors *= primes[j];
			}
			if (primes[j] >= i)
				break;
		}
		if ((noFactors == digits) && (i % mulFactors == 0) && (firstPrime == digits - 1))
		{
			cout << "Consecutive prime: " << i - digits + 1 << endl;
			break;
		}
		else if ((noFactors == digits) && (i % mulFactors == 0) && (firstPrime < digits - 1))
			firstPrime++;
		else
			firstPrime = 0;
	}
}