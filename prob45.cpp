#include "probs.h"

void prob45()
{
	bool equal3 = false;
	double triangular = 0;
	double pentagonal = 0;
	double hexagonal = 0;
	double noT = 286;
	double noP = 165;
	double noH = 143;
	while (!equal3)
	{
		noT++;
		triangular = noT * (noT + 1) / 2;
		while (pentagonal < triangular)
		{
			pentagonal = noP * ((3 * noP) - 1) / 2;
			noP++;
		}
		while (hexagonal < triangular)
		{
			hexagonal = noH * ((noH * 2) - 1);
			noH++;
		}
		if (pentagonal == triangular && hexagonal == triangular)
			equal3 = true;
	}
	cout << "The next number is: "<< (int)triangular << endl;
}