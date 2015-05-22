#pragma once
#include "probs.h"

void prob18_67()
{
	const int N = 100;
	int data[N*(N+1)/2] ;
	int max[N];
	int maxV;
	int val[N];

	ifstream file("txtFiles/p067_triangle.txt");
	bool isOpen = file.is_open();

	string line;
	int v;
	int ctr = 0;
	while (getline(file, line))
	{
		stringstream linestream(line);
		while (linestream >> v)
		{
			data[ctr] = v;
			ctr++;
		}
	}


	max[0] = data[0];
	for (int i = 1; i < N; i++)
	{
		val[i-1] = max[i - 1] + data[(i + 1) * (i + 2) / 2 - 1];
		val[0] = max[0] + data[i * (i+1)/2];
		for (int j = 1; j < i; j++)
		{
			if (max[j-1] > max[j])
				maxV = max[j-1];
			else
				maxV = max[j];

			val[j] = maxV + data[ i *(i+1) /2 + j];
		}
		for (int i = 0; i < N; i++)
			max[i] = val[i];
	}
	
	maxV = max[0];
	for (int i = 1; i < N; i++)
	{
		if (maxV < max[i])
			maxV = max[i];
	}

	cout << maxV << endl;

}