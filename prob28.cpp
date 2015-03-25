#include "probs.h"

void prob28()
{
	long long sum = 1;
	long long p = 1;
	long long q = 0;
	int i, k;
	for (i = 1,  k = 1; i < 1001; i += 2, k++)
	{
		p = i * i;
		q = p;
		for (int j = 0; j < 4; j++)
		{
			q += 2 * k;
			sum += q;
			cout << "i: " << i << "\tP: " << p << "\tQ: " <<  q <<"\tSum: " << sum << endl;
		}
	}
	cin >> p;
}