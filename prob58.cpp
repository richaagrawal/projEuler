#include "probs.h"

void prob58()
{
	double c = 1;
	double step = 0;
	double total = 1;
	double prime = 0;
	double i = 0;
	double percent = 100;
	while (percent > 10)
	{
		i++;
		step = 2 * i;
		for (int j = 0; j < 4; j++)
		{
			c = c + step;
			if (isPrime(c))
				prime++;
			total++;
		}
		percent = prime * 100 / total;
	}

	cout << "Percentage of primes below 10 is for side length " << i*2+1 << endl;
}