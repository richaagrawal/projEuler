#include "probs.h"

void prob206()
{
	unsigned long long sqr;
	unsigned int noDigits;
	unsigned long long i = 1000000030;
	unsigned int digits[19];
	unsigned int j;
	bool flag = false;
	while(true)
	{
		// Last digit has to be 0 for the square to end in 0
		// The third last digit is 9 - so the number should either ed with 30 or 70
		if (flag)
		{
			i += 60;
			flag = false;
		}
		else
		{
			i += 40;
			flag = true;
		}
		sqr = i*i;
		noDigits = log10(sqr) + 1;
		if (noDigits > 19)
			break;
		if (noDigits == 19)
		{
			j = 18;
			while (sqr > 0)
			{
				digits[j] = sqr % 10;
				j--;
				sqr /= 10;
			}
			int k = 1;
			for (; k < 10; k++)
			{
				if (digits[2*(k-1)] != k)
					break;
			}
			if (k > 9)
			{
				cout << "Number whose square is of pattern 1_2_3_4_5_6_7_8_9_0 is :" << i << endl;
				break;
			}
		}
		
	}
}