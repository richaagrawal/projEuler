#include "probs.h"
#include <vector>

bool palindrome2(long no)
{
	vector<int> digits;
	while (no > 1)
	{
		digits.push_back(no % 2);
		no = no / 2;
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

bool palindrome10(long no)
{
	vector<int> digits;
	while (no > 9)
	{
		digits.push_back(no % 10);
		no /= 10;
	}
	digits.push_back(no);
	int l = digits.size();
	while ( l > 0)
	{
		if (digits.at(digits.size() - l) != digits.at(l - 1))
			return false;
		l--;
	}
	return true;
}

void prob36()
{
	bool pal;
	long sum = 0;
	for (int i = 0; i < 1000000; i++)
	{
		if (palindrome10(i))
		{
			if (palindrome2(i))
			{
				cout << i << endl;
				sum += i;
			}
		}
	}

	cout << "Sum of all palindromes: " << sum << endl;
}