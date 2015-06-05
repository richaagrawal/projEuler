#pragma once

#include "probs.h"

void prob42()
{
	int triangleNos[20];
	for (int i = 1; i < 21; i++)
		triangleNos[i - 1] = i * (i + 1) / 2;
	
	ifstream file("txtFiles/p042_words.txt");
	bool isOpen = file.is_open();

	string line;
	char v;
	int val = 0;
	int noTriangleWords = 0;
	while (getline(file, line , ','))
	{
		val = 0;
		stringstream linestream(line);
		while (linestream >> v)
		{
			if (v >= 'A' && v <= 'Z')
				val += v - 'A' + 1;
		}
		for (int i = 0; i < 20; i++)
		{
			if (triangleNos[i] == val)
			{
				noTriangleWords++;
				break;
			}
		}
	}
	cout << "Number of triangle words: " << noTriangleWords << endl;
}