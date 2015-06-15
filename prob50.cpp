#pragma once

#include "probs.h"

void prob50()
{
	vector<long> primes;
	primes.push_back(2);
	for (int i = 3; i < 10000; i += 2)
	{
		if (isPrime(i))
			primes.push_back(i);
	}

	long maxSum = 0;
	long sum = 0;
	int maxTerms = 0;
	for (int i = 0; i < primes.size(); i++)
	{
		sum = 0;
		for (int j = i; j < primes.size(); j++)
		{
			sum += primes.at(j);

			// If sum exceeds - move on to next index
			if (sum > 1000000)
			{
				j = primes.size();
				continue;
			}
			if (isPrime(sum))
			{
				if (j - i + 1 > maxTerms)
				{
					maxTerms = j - i + 1;
					maxSum = sum;
				}
			}
		}
	}

	cout << "Longest Prime: " << maxSum << endl;
}