#include "probs.h"

void prob76()
{
	const int lim = 100;
	unsigned long ways[lim + 1];
	ways[0] = 1;
	for (int i = 1; i <= lim; i++)
		ways[i] = 0;
	for (int i = 1; i < lim; i++)
	{
		for (int j = i; j <= lim; j++)
		{
			ways[j] += ways[j - i];
		}
	}
	cout << "Number of ways to write "  << lim << " : " << ways[lim] << endl;
}