#include "probs.h"

void prob49()
{
	int first, second, third;
	int digits[10];
	int sumF, sumS, sumT;
	for (int i = 1001; i < 9887; i += 2)
	{
		if (!isPrime(i))
			continue;
		for (int j = 2; j < 3333; j += 2)
		{
			first = i;
			second = first + j;
			third = second + j;
			if (second <= 9999 && third <= 9999)
			{
				if (isPrime(second) && isPrime(third))
				{
					for (int k = 0; k < 10; k++)
						digits[k] = 0;
					sumF = sumS = sumT = 0;
					int r;
					while (first > 0)
					{
						r = first % 10;
						digits[r]++;
						sumF += r;
						first /= 10;

						r = second % 10;
						digits[r]++;
						sumS += r;
						second /= 10;

						r = third % 10;
						digits[r]++;
						sumT += r;
						third /= 10;
					}
					int p = 0;
					for (; p < 10; p++)
					{
						if (digits[p] % 3 != 0)
							break;
					}
					if (p > 9)
						if (sumF == sumS && sumS == sumT && i != 1487)
							cout << "Concatenated sequence: " << i << i + j << i + j + j << endl;
				}
			}
		}
	}
}