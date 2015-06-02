#include "probs.h"

void prob37()
{
	int no = 10;
	int t;
	int d = 10;
	bool trunPrimes = true;
	int sumTrunPrimes = 0;
	int noTrunPrimes = 0;
	while (noTrunPrimes != 11)
	{
		t = ++no;
		d = 10;
		trunPrimes = false;
		if (isPrime(no))
		{
			trunPrimes = true;
			while (d < no)
			{
				if ((!isPrime(t / d)) || (!isPrime(t % d)))
				{
					trunPrimes = false;
					break;
				}
				d = d * 10;
			}
		}
		if (trunPrimes)
		{
			sumTrunPrimes += no;
			noTrunPrimes++;
		}
	}
	cout << "Sum of truncatable primes: " << sumTrunPrimes << endl;
}
