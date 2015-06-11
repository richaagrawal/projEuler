#pragma once

#include "probs.h"

void prob38()
{
	long no,t;
	int noDigits;
	int digits[9];
	bool panM;
	int rem;
	long panMax = 0;
	long pan;
	long currDigits;

	for (no = 9; no < 9999; no++)
	{
		// The number has to start with 9 to be largest - otherwise 918273645 is largest
		if (no == 10)
		{
			no = 90;
			continue;
		}
		else if (no == 100)
		{
			no = 900;
			continue;
		}
		else if (no == 1000)
		{
			no = 9000;
			continue;
		}


		noDigits = 0;
		for (int i = 0; i < 9; i++)
			digits[i] = 0;
		panM = true;
		pan = 0;
		
		for (int i = 1; i < 9 && panM == true && noDigits < 9; i++)
		{
			t = no * i;
			currDigits = 0;
			while (t > 0)
			{
				rem = t % 10;
				if (rem == 0)
				{
					panM = false;
					break;
				}
				if (digits[rem - 1] != 0)
					panM = false;
				digits[rem - 1]++;
				currDigits++;
				t /= 10;
			}
			noDigits += currDigits;
			pan *= pow(10, currDigits);
			pan += no * i;
		}
		if (noDigits == 9 && panM && panMax < pan)
		{
			panMax = pan;
		}
	}
	cout << "Maximum pandigital multiple: " << panMax << endl;
}