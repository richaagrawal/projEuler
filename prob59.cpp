#include "probs.h"

double freqAnalysis(vector<char> letters)
{
	double freqA[26] ={8.2, 1.5, 2.8, 4.3, 12.7, 2.2, 2.0, 6.1, 7.0, 0.2, 0.8, 4.0, 2.4, 
					6.7, 7.5, 1.9, 0.1, 6.0, 6.3, 9.1, 2.8, 1.0, 2.4, 0.2, 2.0, 0.1};
	double freqO[26];
	for (int i = 0; i < 26; i++)
		freqO[i] = 0;
	int N = letters.size();
	int ch; 
	for (int i = 0; i < N; i++)
	{
		ch = letters.at(i);
		if (ch >= 'A' && ch <= 'Z')
			ch = ch + 'a' - 'A';
		if (ch >= 'a' && ch <= 'z')
			freqO[ch - 'a']++;
	}
	double score = 0;
	for (int i = 0; i < 26; i++)
	{
		score += abs(freqA[i] - (freqO[i] / N));
	}
	return score;
}

void prob59()
{
	ifstream file("txtFiles/p059_cipher.txt");
	string line, token;
	getline(file, line);
	istringstream ss(line);
	vector<char> characters;
	vector<char> charactersXOR;
	vector<char> temp;
	char t;
	while (getline(ss, token, ','))
	{
		t = (char)(atoi(token.c_str()));
		characters.push_back(t);
	}
	int N = characters.size();
	double minScore, score;
	minScore = 1000;
	
	for (char a = 'a'; a < 'z'; a++)
	{
		for (char b = 'a'; b < 'z'; b++)
		{
			for (char c = 'a'; c < 'z'; c++)
			{
				charactersXOR.clear();
				for (int i = 0; i < N/3; i++)
				{
					charactersXOR.push_back(a ^ characters[i * 3]);
					charactersXOR.push_back(b ^ characters[i * 3 + 1]);
					charactersXOR.push_back(c ^ characters[i * 3 + 2]);
				}
				if (N % 3 == 1)
					charactersXOR.push_back(a ^ characters[N - 1]);
				if (N % 3 == 2)
				{
					charactersXOR.push_back(a ^ characters[N - 2]);
					charactersXOR.push_back(b ^ characters[N - 1]);
				}

				score = freqAnalysis(charactersXOR);
				if (minScore > score)
				{
					minScore = score;
					temp = charactersXOR;
				}
			}
		}
	}

	int result = 0;
	for (int i = 0; i < N; i++)
	{
		result += temp[i];
	}
	cout << "ASCII sum of decryted message: " << result << endl;
}