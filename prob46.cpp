#include "probs.h"

void prob46()
{
	bool conj = true;
	int oddNo = 7;
	int primeNo;
	int squareNo;
	while (conj)
	{
		oddNo += 2;
		if (isPrime(oddNo))
		{
			oddNo += 2;
			continue;
		}
		conj = false;
		for (primeNo = oddNo - 2; primeNo > 2; primeNo -= 2)
		{
			if (!isPrime(primeNo))
				continue;
			squareNo = (oddNo - primeNo) / 2;
			if (isSquare(squareNo))
			{
				conj = true;
				break;
			}
		}
	}
	cout << "Conjecture is false for: " << oddNo << endl;
}