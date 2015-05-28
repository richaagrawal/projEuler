#pragma once

#include "probs.h"

// Desc: http://www.mathblog.dk/project-euler-40-digit-fractional-part-irrational-number/
void prob40()
{
	int lim[] = {9, 189, 2889, 38889, 488889, 5888889};
	int nNines[] = { 9, 99, 999, 9999, 99999, 999999 };
	int prodD = 1;
	int j = 0;
	int limit = 0;
	int digit = 0;
	int div, rem;
	for (int d = 10; d <= 1000000; d *= 10)
	{
		while (lim[j + 1] < d)
		{
			j++;
		}
		limit = lim[j];
		digit = ((d - limit) + ((j + 2) * nNines[j]));
		div = digit / (j + 2);
		rem = digit % (j + 2);

		digit = getDigit(div, rem);
		if (div < 10)
			digit = 1;
		prodD *= digit;
	}

	cout << "Product of digits: " << prodD << endl;
}