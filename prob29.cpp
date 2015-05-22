#pragma once
#include "probs.h"
#include <vector>

void prob29()
{
	vector<double> power;
	for (int i = 2; i <= 100; i++)
	{
		for (int j = 2; j <= 100; j++)
		{
			power.push_back(pow(i, j));
		}
	}

	// Sort the array and run unique to take off duplicates
	sort(power.begin(), power.end());
	auto last = unique(power.begin(), power.end());
	power.erase(last, power.end());

	printf("No of unique powers: %d\n", power.size());
}