#pragma once
#include "probs.h"
#include <vector>

void prob36()
{
	bool pal;
	long sum = 0;
	for (int i = 0; i < 1000000; i++)
	{
		if (palindrome(i, 10))
		{
			if (palindrome(i, 2))
			{
				sum += i;
			}
		}
	}

	cout << "Sum of all palindromes: " << sum << endl;
}