#pragma once

#include "probs.h"

vector<double> fact;

double combn(int n, int r)
{
	double c;
	int s = fact.size();

	while (fact.size() <= n)
	{
		fact.push_back(factorial(s));
		s++;
	}

	c = fact[n] / (fact[r] * fact[n-r]);

	return c;
}

void prob53()
{
	int millionPlus = 0;
	double c;
	for (int n = 0; n < 101; n++)
	{
		for (int r = 0; r < n/2; r++)
		{
			c = combn(n, r);
			if (c > 1000000)
				millionPlus += 2;
		}
		c = combn(n, n / 2);
		if (c > 1000000)
		{
			if (n % 2)
				millionPlus += 2;
			else
				millionPlus++;
		}
	}
	cout << "Numbr of million plus combinations: " << millionPlus << endl;
}