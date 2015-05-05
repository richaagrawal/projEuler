#include "probs.h"
#include <vector>

bool check_abundant(int number)
{
	int sum = 0;
	// Get the sum of divisors
	for (int j = 1; j < number; j++)
	{
		if (number % j == 0)
			sum += j;
	}
	if (sum > number)
		return true;
	else
		return false;
}

// PROB 23: Non-abundant sums
// 1. Find all abundant numbers
// 2. Mark the sum of abundant numbers
// 3. Add all non-marked numbers

void prob23()
{
	vector<int> abundant_nos;
	vector<bool> is_abundant_sum(28123);
	for (int i = 0; i < 28123; i++)
	{
		is_abundant_sum[i] = false;
		if (check_abundant(i))
		{
			abundant_nos.push_back(i);
		}
	}

	for (int i = 0; i < abundant_nos.size(); i++)
	{
		int n = abundant_nos.at(i);
		for (int j = i; j < abundant_nos.size(); j++)
		{
			int sum_abundant = n + abundant_nos.at(j);
			if (sum_abundant < 28123)
				is_abundant_sum[sum_abundant] = true;
		}
	}

	long sum_non_abundant = 0;
	for (int i = 0; i < 28123; i++)
	{
		if (is_abundant_sum[i] == false)
			sum_non_abundant += i;
	}

	cout << "Sum of all non-abundant sums" << sum_non_abundant << endl;
}