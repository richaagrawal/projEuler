#pragma once
#include "probs.h"
#include <vector>

// Checks if the number is prime
bool digitEven = false;

// Generate circular numbers
vector<int> getCircularNos(long no)
{
	long n = no;
	int noDigits = 0;
	vector<int> digits;
	while (n >= 10)
	{
		if (n % 10 % 2 == 0)
		{
			digitEven = true;
			return digits;
		}
		digits.push_back(n % 10);
		noDigits++;
		n = n / 10;
	}
	digits.push_back(n);
	noDigits++;

	vector<int> circularNo;
	long nom;
	switch (noDigits)
	{
	case 1:
		circularNo.push_back(no);
		break;

	case 2:
		nom = digits[0] * 10 + digits[1];
		circularNo.push_back(nom);
		break;

	case 3:
		nom = digits[1] * 100 + digits[0] * 10 + digits[2];
		circularNo.push_back(nom);
		nom = digits[0] * 100 + digits[2] * 10 + digits[1];
		circularNo.push_back(nom);
		break;

	case 4:
		nom = digits[2] * 1000 + digits[1] * 100 + digits[0] * 10 + digits[3];
		circularNo.push_back(nom);
		nom = digits[1] * 1000 + digits[0] * 100 + digits[3] * 10 + digits[2];
		circularNo.push_back(nom);
		nom = digits[0] * 1000 + digits[3] * 100 + digits[2] * 10 + digits[1];
		circularNo.push_back(nom);
		break;

	case 5:
		nom = digits[3] * 10000 + digits[2] * 1000 + digits[1] * 100 + digits[0] * 10 + digits[4];
		circularNo.push_back(nom);
		nom = digits[2] * 10000 + digits[1] * 1000 + digits[0] * 100 + digits[4] * 10 + digits[3];
		circularNo.push_back(nom);
		nom = digits[1] * 10000 + digits[0] * 1000 + digits[4] * 100 + digits[3] * 10 + digits[2];
		circularNo.push_back(nom);
		nom = digits[0] * 10000 + digits[4] * 1000 + digits[3] * 100 + digits[2] * 10 + digits[1];
		circularNo.push_back(nom);
		break;

	case 6:
		nom = digits[4] * 100000 + digits[3] * 10000 + digits[2] * 1000 + digits[1] * 100 + digits[0] * 10 + digits[5];
		circularNo.push_back(nom);
		nom = digits[3] * 100000 + digits[2] * 10000 + digits[1] * 1000 + digits[0] * 100 + digits[5] * 10 + digits[4];
		circularNo.push_back(nom);
		nom = digits[2] * 100000 + digits[1] * 10000 + digits[0] * 1000 + digits[5] * 100 + digits[4] * 10 + digits[3];
		circularNo.push_back(nom);
		nom = digits[1] * 100000 + digits[0] * 10000 + digits[5] * 1000 + digits[4] * 100 + digits[3] * 10 + digits[2];
		circularNo.push_back(nom);
		nom = digits[0] * 100000 + digits[5] * 10000 + digits[4] * 1000 + digits[3] * 100 + digits[2] * 10 + digits[1];
		circularNo.push_back(nom);
		break;

	}

	return circularNo;
}

// Problem 35: circular primes
void prob35()
{
	int noCircPrimes = 0;
	for (int i = 2; i <= 999999; i++)
	{
		if (isPrime(i))
		{
			bool circPrimes = true;
			vector<int> circNos = getCircularNos(i);
			if (digitEven == true)
			{
				digitEven = false;
				continue;
			}
			for (unsigned int j = 0; j < circNos.size(); j++)
			{
				if (!isPrime(circNos.at(j)))
					circPrimes = false;
			}

			if (circPrimes == true)
			{
				noCircPrimes++;
			}
		}
	}
	cout << endl;
	cout << "Number of circular primes below 1 million: " << noCircPrimes << endl;
}