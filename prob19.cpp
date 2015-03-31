#include "probs.h"

void prob19()
{
	long long noSunday = 0;
	int nodays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int currentDay = 1;
	int noDaysInMonth = 0;
	for (int i = 1900; i <= 2000; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			noDaysInMonth = nodays[j];
			if ((i % 4 == 0) && ((i % 100 != 0) || (i % 400 == 0)) )
			{
				if(j == 2)
					noDaysInMonth++;
			}

			currentDay += noDaysInMonth;
			currentDay = currentDay % 7;
			if (currentDay == 0)
				noSunday++;
		}
		std::cout << "Year: " << i << "\tNumber of Sundays: " << noSunday << std::endl;
	}
}