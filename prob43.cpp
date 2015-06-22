#include "probs.h"
using namespace std;

void prob43()
{
	int digits[10];
	unsigned long long no;
	int ctr;
	unsigned long long sum = 0;
	int rem;
	int panDigital[10];
	for (unsigned long long i = 1023456789; i <= 9876543210; i++)
	{
		for (int j = 0; j < 10; j++)
			panDigital[j] = digits[j] = 0;
		//Since the first digit cant be 5 as 5 digit has to be five
		if (i == 5000000000)
		{
			i = 6012345789;
			continue;
		}
		no = i;
		ctr = 9;
		while (no > 0)
		{
			rem = no % 10;
			digits[ctr] = rem;
			no /= 10;
			if (ctr != 5 && rem == 5)
				break;
			if (panDigital[rem] != 0)
				break;
			if (ctr == 7 && ((digits[7] * 10 + digits[8] - digits[9] * 5) % 17 != 0))
				break;
			else if (ctr == 6 && ((digits[6] * 10 + digits[7] - digits[8] * 9) % 13 != 0))
				break;
			else if (ctr == 5 && (abs(digits[5] - digits[6] + digits[7]) % 11 != 0))
				break;
			else if (ctr == 4 && (digits[4] * 100 + digits[5] * 10 + digits[6]) % 7 != 0)
				break;
			else if (ctr == 3 && (digits[3] % 2 != 0))
				break;
			else if (ctr == 2 && ((digits[2] + digits[3] + digits[4]) % 3 != 0))
				break;
			panDigital[rem]++;
			ctr--;
		}
		if (ctr >= 0)
			continue;

		cout << "Divisible numbers: " << i << endl;
		sum += i;
	}
	cout << "Sum of numbers: " << sum << endl;
}