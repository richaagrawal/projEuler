#pragma once
#include "probs.h"

void prob52()
{
	int digits[10], digitsM[10];
	long no;
	long t;
	int rem;
	int noDigits;
	int noDigitsM; 
	bool permM;
	int mult = 6;

	for (no = 10; no < 1000000000; no++)
	{
		noDigits = 0;
		t = no;
		for (int i = 0; i < 10; i++)
			digits[i] = 0;

		// Build digits for 1x
		while (t > 0)
		{
			rem = t % 10;
			digits[rem]++;
			t /= 10;
			noDigits++;
		}

		// The number should have 1 as a first digit otherwise multiplying by 6 would increase the digits
		if (rem > 1)
			continue;

		// Check for 2x - 6x if they have same digits
		permM = true;
		for (int j = 2; j < mult && permM == true; j++)
		{
			noDigitsM = 0;
			t = no * j;
			for (int k = 0; k < 10; k++)
				digitsM[k] = 0;
			while (t > 0)
			{
				rem = t % 10;
				digitsM[rem]++;
				t /= 10;
				noDigitsM++;
			}
			if (noDigits != noDigitsM)
			{
				permM = false;
				break;
			}
			for (int k = 0; k < 10; k++)
			{
				if (digits[k] !=  digitsM[k])
				{
					permM = false;
					break;
				}
			}
		}

		if (permM)
		{
			cout << no << endl;
			break;
		}
	}
}