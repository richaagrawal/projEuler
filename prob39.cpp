#include "probs.h"

void prob39()
{
	int noSol = 0;
	int c;
	int maxSol = 0, maxP = 0;
	for (int p = 1; p < 1000; p++)
	{
		noSol = 0;
		for (int a = 1; a < p - 2; a++)
		{
			for (int b = a + 1; b < p - 2; b++)
			{
				c = p - a - b;
				if (a*a + b*b - c*c == 0)
					noSol++;
			}
		}
		if (maxSol < noSol)
		{
			maxSol = noSol;
			maxP = p;
		}
	}
	cout << "Value of P with maximum solution: \t" << maxP << endl;
}