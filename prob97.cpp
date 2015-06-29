#include "probs.h"


// Ref: http://code.jasonbhill.com/c/project-euler-97/
void prob97()
{
	unsigned long long mPrime = 2;
	unsigned long long tenD = 10000000000;
	for (unsigned long i =	1; i < 7830457; i++)
	{
		mPrime = (mPrime << 1) % tenD;
	}
	mPrime *= 28433;
	mPrime++;
	mPrime %= tenD;
	cout << "Last ten digits: " << mPrime  << endl;
}