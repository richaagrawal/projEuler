#include "probs.h"

void prob387()
{
	const unsigned int N = 9;
	const unsigned long lim = 10000000000;
	short int digits[N];
	bool* primes = new bool[lim];
	isPrimeSieve(primes,lim);
	unsigned long no;
	int c;
	unsigned long harsh = 0;
	unsigned long digitSum = 0;
	unsigned long digit = 0;
	unsigned long div = 0;
	unsigned long rem = 0;
	double sumHarshadNo = 0;

	for (int i = 0; i < N; i++)
		digits[i] = 0;

	for (unsigned long i = 11; i < lim/10; i++)
	{
		c = N - 1;
		no = i;
		// Get digits
		while (no > 0)
		{
			digits[c] = no % 10;
			no /= 10;
			c--;
		}
		digitSum = 0;
		digit = 0;
		c++;
		// check if it is harshad number
		for (; c < N; c++)
		{
			digit = digit * 10 + digits[c];
			digitSum += digits[c];
			rem = digit % digitSum;
			if (rem != 0)
				break;
		}
		if (c != N)
			continue;

		// check if it is strong harshad number
		div = digit / digitSum;

		if (!primes[div - 1])
			continue;

		//  Add 1,3,5,7,9 to the end to see if it is prime
		for (int k = 1; k <= 9; k += 2)
		{
			harsh = i * 10 + k;
			if (primes[harsh - 1])
			{
				sumHarshadNo += harsh;
				//cout << harsh << endl;
			}
		}
	}

	cout << "sum of harshad numbers below " << lim << " is: " << fixed << sumHarshadNo << endl;
}