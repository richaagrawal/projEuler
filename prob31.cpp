#pragma once

#include "probs.h"

void prob31()
{
	int noWays = 1; // For using 200p. 
	for (int one = 0; one < 201; one++)
	{
		for (int two = 0; two < 101; two++)
		{
			for (int five = 0; five < 41; five++)
			{
				for (int ten = 0; ten < 21; ten++)
				{
					for (int twenty = 0; twenty < 11; twenty++)
					{
						for (int fifty = 0; fifty < 5; fifty++)
						{
							for (int hundred = 0; hundred < 3; hundred++)
							{
								int totalP = one * 1 + two * 2 + five * 5 + ten * 10 + twenty * 20 + fifty * 50 + hundred * 100;
								if (totalP == 200)
									noWays++;
							}
						}
					}
				}
			}
		}
	}
	cout << "Total number of ways: " << noWays << endl;
}