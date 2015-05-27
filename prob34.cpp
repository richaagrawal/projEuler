#pragma once
#include "probs.h"
#include <vector>

void prob34()
{
	double factNo, factDigits;
	factNo = factDigits = 0;
	double rem, div;

	for (double no = 10; no < 50000; no++)
	{
		rem = 0;
		div = no;
		factDigits = 0;
		while (div > 9)
		{
			rem = (double)((long long)div % 10);
			div = div / 10;
			factDigits += factorial(rem);
		}
		factDigits += factorial(div);

		if (factDigits == no)
			factNo += factDigits;
	}
	printf("Sum of factorial(digits) = number is: %.0f", factNo);
}