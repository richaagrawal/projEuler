#pragma once
#include "probs.h"

void prob33()
{
	int numr1, numr2; // Numerator digits 
	int denr1, denr2;  // Denominator digits
	
	int numU, numR, denU, denR = 0;

	int prodDen = 1;
	int prodNum = 1;

	for (int numr = 11; numr < 99; numr++)
	{
		for (int denr = 11; denr < 99; denr++)
		{
			numR = numU = denR = denU = -1;

			numr1 = numr / 10;
			numr2 = numr % 10;

			denr1 = denr / 10;
			denr2 = denr % 10;

			// Trivial case
			if ((numr1 == 0 || numr2 == 0) && (denr1 == 0 || denr2 == 0))
				continue;

			if (numr1 == denr1 || numr1 == denr2)
				numR = numr1;
			else
				numU = numr1;

			if (numr2 == denr1 || numr2 == denr2)
				numR = numr2;
			else
				numU = numr2;
	
			// It either has both digits unique or both repeating digits
			if (numU == -1 || numR == -1)
				continue;

			if (denr1 == numR)
				denU = denr2;
			else
				denR = denr1;

			if ((float)numU / denU - (float)numr / denr == 0)
			{
				prodDen *= denU;
				prodNum *= numU;
			}
		}
	}

	int gcdD = gcd(prodDen, prodNum);
	cout << "Product of Denominator " << prodDen/gcdD << endl;

}