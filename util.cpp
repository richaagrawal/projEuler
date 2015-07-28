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

void isPrimeSieve(bool arr[], int n)
{
	if (n < 2)
		return;
	for (int i = 0; i < n; i++)
		arr[i] = true;
	for (int i = 1; i < n; i++)
	{
		if (arr[i])
		{
			int k = 2;
			while (k * (i + 1) <= n)
			{
				arr[k * (i + 1) - 1] = false; // minus 1 because index starts from 0.
				++k;
			}
		}
	}
}

bool palindrome(long long no, int base)
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

double getpalindromeD(double no)
{
	double palin = 0;
	while (true)
	{
		palin *= 10;
		palin += no;
		no = floor(no / 10);
		palin -= no * 10;
		if (no < 10)
		{
			palin *= 10;
			palin += no;
			break;
		}
	}
	return palin;
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


bool isPandigital(long no)
{
	int digits[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int rem;
	int noDigits = 0;
	while (no > 0)
	{
		rem = no % 10 - 1;
		if (rem == -1 || digits[rem] != 0)
			return false;
		digits[rem]++;
		no /= 10;
		noDigits++;
	}
	for (int i = 0; i < noDigits; i++)
	{
		if (digits[i] != 1)
			return false;
	}
	return true;
}

bool isSquare(long no)
{
	int hexDigits = no & 0xF;
	if (!(hexDigits == 0x0 || hexDigits == 0x1 || hexDigits == 0x4 || hexDigits == 0x9))
		return false;
	if ((int)sqrt(no)*(int)sqrt(no) == no)
		return true;
	return false;
}