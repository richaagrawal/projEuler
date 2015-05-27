#pragma once
#include "probs.h"

// Put all previous remainder in an array - check when we hit the same number and return that. 
// Return 0 if it is non-recurrent. 
int recurringDigits(int no)
{
	int div;
	if (no < 10)
		div = 10;
	else if (no < 100)
		div = 100;
	else if (no < 1000)
		div = 1000;

	int prevDigits[1000];
	int digitToUse = 0;
	while (div > 0)
	{
		div = div % no;
		if (div == 0)
			return 0;
		for (int i = 0; i < digitToUse; i++)
		{
			if (div == prevDigits[i])
				return digitToUse;
		}
		prevDigits[digitToUse] = div;
		digitToUse++;
		div *= 10;
	} 
	return digitToUse;
}



void prob26()
{
	int max = 0;
	int rec = 0;
	int val = 0;
	for (int i = 2; i < 1000; i++)
	{
		rec = recurringDigits(i);
		if (rec > max)
		{
			max = rec;
			val = i;
		}
	}
	cout << "Maximum recurring digits is for 1/" << val << endl;
}