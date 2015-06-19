#include "probs.h"

// Tried wih double but was always overrunning the buffer
// Creted an array of integers - ref: http://discuss.codechef.com/questions/7349/computing-factorials-of-a-huge-number-in-cc-a-tutorial

void prob56()
{
	int upper[500];
	int lower[500];
	int sum[500];
	int first[500];
	int second[2];
	int noTerms = 0;
	first[0] = 8;
	first[1] = 9;
	second[0] = 9;
	second[1] = 8;
	noTerms = 2;
	int maxSum = 0;
	for (int outer = 2; outer < 100; outer++)
	{
		second[0] = first[1] = outer / 10;
		second[1] = first[0] = outer % 10;
		noTerms = 2;
		for (int inner = 1; inner < 100; inner++)
		{
			for (int i = 0; i < noTerms; i++)
			{
				upper[i] = first[i] * second[1];
				lower[i] = first[i] * second[0];
			}
			sum[noTerms] = lower[noTerms - 1];
			for (int i = noTerms - 1; i > 0; i--)
			{
				sum[i] = upper[i] + lower[i - 1];
			}
			sum[0] = upper[0];
			int res = 0;

			for (int i = 0; i < noTerms; i++)
			{
				res = res + sum[i];
				first[i] = (res) % 10;
				res /= 10;
			}
			res = res + sum[noTerms];
			while (res > 0)
			{
				first[noTerms] = res % 10;
				res /= 10;
				noTerms++;
			}
			int sumDigits = 0;
			for (int i = noTerms - 1; i >= 0; i--)
			{
				sumDigits += first[i];
			//	cout << first[i];
			}
			//cout << "\t" << sumDigits << endl;
			if (sumDigits > maxSum)
				maxSum = sumDigits;
		}
	}
	std::cout << "\nMaximum digital sum: " << maxSum << endl;
}