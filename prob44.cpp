#include "probs.h"

// Trick to reduce time: Check if the number is pandigital
// n(3n-1)/2 = x => n = 1+sqrt(1+24x)/6
void prob44()
{
	long pentagonal[2500];
	int N = 2500;
	long sum, diff;
	for (int i = 0; i < N; i++)
	{
		pentagonal[i] = (i+1) * (3 * (i+1) - 1) / 2;
	}
	bool found = false;
	long nD, nS;
	int n;
	for (int i = 0; i < N; i++)
	{
		if (found)
			break;
		for (int j = i + 1; j < N; j++)
		{
			diff = pentagonal[j] - pentagonal[i];
			nD = 1 + 24 * diff;
			if (!isSquare(nD))
				continue;
			n = sqrt(nD) + 1;
			if (n % 6 != 0)
				continue;

			sum = pentagonal[j] + pentagonal[i];
			nS = 1 + 24 * sum;
			if (!isSquare(nS))
				continue;
			n = sqrt(nS) + 1;
			if (n % 6 != 0)
				continue;

			cout << "Distance: " << diff << endl;
			found = true;
		}
	}
}