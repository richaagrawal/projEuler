#include "probs.h"

// Maxing out even the double implementation
// Used arrays to store the number
// Perform addition and subtraction element wise

void prob57()
{
	const short int N = 500;
	short int nr[N], dr[N];
	for (int i = 0; i < N; i++)
		nr[i] = dr[i] = 0;
	short int nrC, drC;
	nrC = drC = N - 1;
	nr[N-1] = dr[N-1] = 1;
	short int no = 0;
	short int carry = 0;
	short int p = 0;


	for (int i = 0; i < 1000; i++)
	{
		carry = 0;
		for (int j = N - 1; j >= nrC; j--)
		{
			p = nr[j] + dr[j] + dr[j] + carry;
			nr[j] = p % 10;
			carry = p / 10;
		}
		if (carry > 0)
		{
			--nrC;
			nr[nrC] = carry;
		}

		carry = 0;
		drC = nrC;
		for (int j = N - 1; j >= nrC; j--)
		{
			p = nr[j] - dr[j] - carry;
			if (p == 0 && j == nrC)
				drC++;
			if (p >= 0)
			{
				dr[j] = p;
				carry = 0;
			}
			else
			{
				p = nr[j] + 10 - dr[j] - carry;
				dr[j] = p;
				carry = 1;
			}
		}
		
		if (N - nrC > N - drC)
			no++;
	}

	cout << "Number of digits where numerator has more digits than denominator: " << no << endl;
}