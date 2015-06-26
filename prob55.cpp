#include "probs.h"

void prob55()
{
	double pal = 0;
	int ctr;
	int noLychrel = 0;
	double getPal;
	for (int i = 1; i <= 10000; i++)
	{
		ctr = 0;
		pal = i;
		getPal = getpalindromeD(pal);
		while (ctr < 50)
		{
			pal += getPal;
			getPal = getpalindromeD(pal);
			if (pal == getPal)
				break;
			ctr++;
		}
		if (ctr == 50)
		{
			noLychrel++;
		}
	}
	cout << "Number of lychrel numbers: " << noLychrel << endl;
}