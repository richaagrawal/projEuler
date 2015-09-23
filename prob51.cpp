#include "probs.h"

void prob51()
{
	// http://math.stackexchange.com/questions/166800/primality-and-repeated-digits
	// http://blog.singhanuvrat.com/problems/project-euler-problem-51-prime-digit-replacements
	// Based on above, it has to be 6 digit number with 3 replacements
	const int N = 100000;
	bool primeArr[N*10];
	isPrimeSieve(primeArr, N*10);
	char strNo[7];

	// 3 replacements or 6 digit numbers - 1 denotes the replacement
	// Last digit cant be replaced as that would generate max 4 numbers: 
	// 001110, 010110, 011010, 011100, 101010, 101100, 100110, 110010, 110100, 111000
	const int mask[10][6] =	
	{	
	{ 0, 0, 1, 1, 1, 0 }, 
	{ 0, 1, 0, 1, 1, 0 },
	{ 0, 1, 1, 0, 1, 0 },
	{ 0, 1, 1, 1, 0, 0 },
	{ 1, 0, 1, 0, 1, 0 },
	{ 1, 0, 1, 1, 0, 0 },
	{ 1, 0, 0, 1, 1, 0 },
	{ 1, 1, 0, 0, 1, 0 },
	{ 1, 1, 0, 1, 0, 0 },
	{ 1, 1, 1, 0, 0, 0 }};
	int noPrimes;
	int dgt[3];
	int no;
	bool found = false;
	int cnt;

	int i;
	for (i = N + 1; i < N * 10; i+=2)
	{
		if (!primeArr[i - 1])
			continue;

		for (int a = 0; a < 10; a++)
		{
			cnt = 0;
			for (int b = 0; b < 6; b++)
			{
				if (mask[a][b] == 1)
				{
					dgt[cnt] = b;
					cnt++;
				}
			}
			itoa(i, strNo, 10);
			if (!(strNo[dgt[0]] == strNo[dgt[1]] && strNo[dgt[1]] == strNo[dgt[2]]))
				continue;

			noPrimes = 0;
			for (int j = strNo[dgt[0]]; j < 58; j++)
			{
				for (int k = 0; k < 3; k++)
					strNo[dgt[k]] = j;

				no = atoi(strNo); 
				if (primeArr[no - 1])
					noPrimes++;
			}
			if (noPrimes == 8)
			{
				found = true;
			}
		}

		if (found)
			break;

	}
	cout << "Smallest 8 prime number: " << i << endl;
}
