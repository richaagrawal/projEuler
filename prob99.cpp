#include "probs.h"

// loga^b = b*loga
void prob99()
{
	ifstream file("txtFiles/p099_base_exp.txt");
	bool isOpen = file.is_open();

	string line;
	int v;
	int lineNo = 0;
	long base, exponent;
	double power;
	double maxPower = 0;
	int maxPowerLine = 0;

	while (getline(file, line))
	{
		stringstream linestream(line);
		linestream >> base;
		if (linestream.peek() == ',')
			linestream.ignore();
		linestream >> exponent;

		lineNo++;
		power = exponent * log(base);
		if (power > maxPower)
		{
			maxPower = power;
			maxPowerLine = lineNo;
		}
	}

	cout << "Largest power corresponds to line number: " << maxPowerLine;
}