#include "probs.h"

void prob81()
{
	ifstream file("txtFiles/p081_matrix.txt");
	bool isOpen = file.is_open();

	string line;
	int v;
	int row = 0, col = 0;
	const int R = 80;
	int data[R][R];


	while (getline(file, line))
	{
		stringstream linestream(line);
		col = 0;
		while (linestream >> v)
		{
			data[row][col] = v;
			col++;
			if (linestream.peek() == ',')
				linestream.ignore();
		}
		row++;
	}


	long long temp[R][R];
	temp[0][0] = data[0][0];

	for (int i = 1; i <= R - 1; i++)
	{
		temp[0][i] = data[0][i] + temp[0][i - 1];
		temp[i][0] = data[i][0] + temp[i - 1][0];
	}

	for (int i = 1; i <= R - 1; i++)
	{
		for (int j = 1; j <= R - 1; j++)
		{
			if (temp[i - 1][j] < temp[i][j - 1])
				v = temp[i - 1][j];
			else
				v = temp[i][j - 1];
			temp[i][j] = v + data[i][j];
		}
	}

	cout << "Minimal path sum : " << temp[R - 1][R - 1] << endl;
}