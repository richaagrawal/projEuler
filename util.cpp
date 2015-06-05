#include "util.h"

bool isPrime(long no)
{
	if (no == 1)
		return false;
	int limit = (int)sqrt(no);
	for (int i = 2; i <= limit; i++)
	{
		if (no % i == 0)
			return false;
	}
	return true;
}

bool palindrome(long no, int base)
{
	vector<int> digits;
	while (no > base - 1)
	{
		digits.push_back(no % base);
		no = no / base;
	}
	digits.push_back(no);
	int l = digits.size();
	while (l > 0)
	{
		if (digits.at(digits.size() - l) != digits.at(l - 1))
			return false;
		l--;
	}
	return true;
}



double factorial(double no)
{
	double fact = 1;
	for (double i = 2; i <= no; i++)
	{
		fact *= i;
	}
	return fact;
}


void swap(int *i, int *j)
{
	int temp = *i;
	*i = *j;
	*j = temp;
}


int getDigit(long no, int pos)
{
	int digit = 0;

	vector<int> digits;
	while (no > 9)
	{	
		digits.push_back(no % 10);
		no = no / 10;
	}
	digits.push_back(no);

	digit = digits.at(digits.size() - pos);

	return digit;
}

// Have to check this
long gcd(long a, long b)
{
	vector<int> divA, divB;
	for (int i = 1; i <= a; i++)
	{
		if (a % i == 0)
			divA.push_back(i);
	}

	for (int i = 1; i <= b; i++)
	{
		if (b % i == 0)
			divB.push_back(i);
	}

	int ai = 0, bi = 0;
	int div = 1;
	for (; ai < divA.size() && bi < divB.size();)
	{
		if (divA.at(ai) == divB.at(bi))
		{
			div = divA.at(ai);
			ai++;
			bi++;
		}
		else if (divA.at(ai) < divB.at(bi))
			ai++;
		else
			bi++;
	}
	return div;
}