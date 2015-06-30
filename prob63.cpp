#include "probs.h"

// Let the number be x^n
// x has to be less than 10 - because from 10 onwards x^n > n
// For i to 9, we check till we get the same number of digits as power
void prob63()
{
	int noP = 0;
	double p;
	int noD = 0;
	int j;
	for (int i = 1; i < 10; i++)
	{
		p = 1;
		j = 0;
		while (true)
		{
			j++;
			p *= i;
			noD = log10(p) + 1;
			if (noD == j)
				noP++;
			else
				break;
		}
	}
	cout << "Powerful digit count: " << noP << endl;
}