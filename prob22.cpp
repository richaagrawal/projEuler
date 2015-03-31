#include "probs.h"
#include <vector>

void prob22()
{
	long long finalScore = 0;
	long score = 0;

	ifstream file("txtFiles/p022_names.txt");
	bool isOpen = file.is_open();

	string line;
	getline(file, line);
	vector<string> names;

	istringstream ss(line);
	string name;
	while (ss)
	{
		if (!getline(ss, name, ','))
			break;
		name = name.substr(1, name.length()-2);
		names.push_back(name);
	}

	sort(names.begin(), names.end());


	for (int i = 0; i < names.size(); i++)
	{
		name = names.at(i);
		score = 0;
		for (int j = 0; j < name.length(); j++)
			score += name[j] - 64;
		finalScore += score * (i+1);
	}
	
	cout << "Score =  " << finalScore << endl;
}