#include "probs.h"

unsigned long squareAdd(unsigned long no)
{
	unsigned long result = 0;
	int rem = 1;
	while (no > 0)
	{
		rem = no % 10;
		result += rem * rem;
		no /= 10;
	}
	return result;
}

void prob92()
{
	unsigned long res;
	unsigned long no89 = 0;
	for (unsigned long i = 1; i < 10000000; i++)
	{
		res = i;
		while (1)
		{
			//cout << res;
			if (res == 89)
			{
				no89++;
				break;
			}
			if (res == 1)
				break;
			res = squareAdd(res);
			//cout << " -> ";
		}
		//cout << endl;
	}
	cout << "\n\nNumbers ending at 89: " << no89 << endl;
}