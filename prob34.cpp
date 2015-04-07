#include "probs.h"
#include <vector>

double factorial(double no)
{
	double fact = 1;
	for (double i = 2; i <= no; i++)
	{
		fact *= i;
	}
	return fact;
}

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
			rem = (long long)div % 10;
			div = div / 10;
			factDigits += factorial(rem);
		}
		factDigits += factorial((long long)div);

		if (factDigits == no)
			factNo += factDigits;
	}
	printf("Sum of factorial(digits) = number is: %.0f", factNo);
}