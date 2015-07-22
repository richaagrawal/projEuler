#include "probs.h"

void prob54()
{
	ifstream file("txtFiles/p054_poker.txt");
	if (!file.is_open())
		cout << "Cannot open file" << endl;
	string line; 
	string val; 
	string one, two;

	char oneSuite[5], twoSuite[5];
	char oneFace[5], twoFace[5];
	int oneSuites[4], oneFaces[13];
	int twoSuites[4], twoFaces[13];

	int playerOneWins = 0;
	int playerTwoWins = 0;

	bool oneSameSuites, twoSameSuites;
	bool oneConsecVal, twoConsecVal;

	int p1, p2;
	int highp1, highp2;
	int highp11, highp21;
	int highp12, highp22;
	int temp;

	while (getline(file, line))
	{
		one = line.substr(0, 14);
		two = line.substr(15, 26);
		// parse each hand into suite and value
		for (int i = 0; i < 5; i++)
		{
			oneFace[i] = one[3 * i];
			oneSuite[i] = one[3 * i + 1];
			twoFace[i] = two[3 * i];
			twoSuite[i] = two[3 * i + 1];
			if (oneFace[i] == 'T')
				oneFace[i] = '9' + 1;
			if (oneFace[i] == 'J')
				oneFace[i] = '9' + 2;
			if (oneFace[i] == 'Q')
				oneFace[i] = '9' + 3;
			if (oneFace[i] == 'K')
				oneFace[i] = '9' + 4;
			if (oneFace[i] == 'A')
				oneFace[i] = '9' + 5;

			if (twoFace[i] == 'T')
				twoFace[i] = '9' + 1;
			if (twoFace[i] == 'J')
				twoFace[i] = '9' + 2;
			if (twoFace[i] == 'Q')
				twoFace[i] = '9' + 3;
			if (twoFace[i] == 'K')
				twoFace[i] = '9' + 4;
			if (twoFace[i] == 'A')
				twoFace[i] = '9' + 5;

			if (oneSuite[i] == 'H')
				oneSuite[i] = 'D' + 1;
			if (oneSuite[i] == 'S')
				oneSuite[i] = 'D' + 2;

			if (twoSuite[i] == 'H')
				twoSuite[i] = 'D' + 1;
			if (twoSuite[i] == 'S')
				twoSuite[i] = 'D' + 2;
		}

		// Sort the cards based on face
		for (int i = 0; i < 5; i++)
		{
			for (int j = i + 1; j < 5; j++)
			{
				if (oneFace[j] < oneFace[i])
				{
					temp = oneFace[j];
					oneFace[j] = oneFace[i];
					oneFace[i] = temp;
					temp = oneSuite[j];
					oneSuite[j] = oneSuite[i];
					oneSuite[i] = temp;
				}
				if (twoFace[j] < twoFace[i])
				{
					temp = twoFace[j];
					twoFace[j] = twoFace[i];
					twoFace[i] = temp;
					temp = twoSuite[j];
					twoSuite[j] = twoSuite[i];
					twoSuite[i] = temp;
				}
			}
		}

		// Preprocessing
		// 1. Create an array with values of each card
		// 2. Create an array with values of each suite
		for (int i = 0; i < 4; i++)
		{
			oneSuites[i] = 0;
			twoSuites[i] = 0;
		}
		for (int i = 0; i < 13; i++)
		{
			oneFaces[i] = 0;
			twoFaces[i] = 0;
		}
		for (int i = 0; i < 5; i++)
		{
			oneFaces[oneFace[i] - '2']++;
			twoFaces[twoFace[i] - '2']++;
			oneSuites[oneSuite[i] - 'C']++;
			twoSuites[twoSuite[i] - 'C']++;
		}

		oneSameSuites = false;
		twoSameSuites = false;
		for (int i = 0; i < 4; i++)
		{
			if (oneSuites[i] == 5)
				oneSameSuites = true;
			if (twoSuites[i] == 5)
				twoSameSuites = true;
		}

		oneConsecVal = false;
		twoConsecVal = false;
		for (int i = 0; i < 8; i++)
		{
			if (oneFaces[i] && oneFaces[i + 1] && oneFaces[i + 2] && oneFaces[i + 3] && oneFaces[i + 4])
				oneConsecVal = true;
			if (twoFaces[i] && twoFaces[i + 1] && twoFaces[i + 2] && twoFaces[i + 3] && twoFaces[i + 4])
				twoConsecVal = true;
		}

		// Check if player one/two has royal flush
		if (oneSameSuites && oneConsecVal && oneFace[0] == '9' + 1)
		{
			//cout << "Royal flush - player one wins" << endl;
			playerOneWins++;
			continue;
		}
		else if (twoSameSuites && twoConsecVal && twoFace[0] == '9' + 1)
		{
			//cout << "Royal flush - player two wins" << endl;
			playerTwoWins++;
			continue;
		}

		// Check for straight flush
		if (oneSameSuites && oneConsecVal && twoSameSuites && twoConsecVal)
		{
			if (oneFace[4] > twoFace[4])
			{
				//cout << "Straight flush - player one wins" << endl;
				playerOneWins++;
			}
			else
			{
				//cout << "Straight flush - player two wins" << endl;
				playerTwoWins++;
			}
			continue;
		}
		if (oneSameSuites && oneConsecVal)
		{
			//cout << "Straight flush - player one wins" << endl;
			playerOneWins++;
			continue;
		}
		else if (twoSameSuites && twoConsecVal)
		{
			//cout << "Straight flush - player two wins" << endl;
			playerTwoWins++;
			continue;
		}

		// Four of a kind
		p1 = p2 = 0;
		highp1 = highp2 = 0;
		for (int i = 0; i < 13; i++)
		{
			if (oneFaces[i] == 4)
				p1 = i+1;
			if (twoFaces[i] == 4)
				p2 = i+1;
			if (oneFaces[i] == 1)
				highp1 = i+1;
			if (twoFaces[i] == 1)
				highp2 = i+1;
		}
		if (p1 != 0 || p2 != 0)
		{
			if (p1 > p2)
			{
				//cout << "Four of a kind - player one wins" << endl;
				playerOneWins++;
			}
			else if (p2 > p1)
			{
				//cout << "Four of a kind - player two wins" << endl;
				playerTwoWins++;
			}
			else if (p1 == p2 && highp1 > highp2)
			{
				//cout << "Four of a kind - player one wins" << endl;
				playerOneWins++;
			}
			else
			{
				//cout << "Four of a kind - player two wins" << endl;
				playerTwoWins++;
			}
			continue;
		}

		// Full house
		p1 = p2 = 0;
		highp1 = highp2 = 0;
		highp11 = highp12 = 0;
		highp21 = highp22 = 0;
		for (int i = 0; i < 13; i++)
		{
			if (oneFaces[i] == 1)
				highp12 = i+1;
			if (oneFaces[i] == 2)
			{
				p1 += 2;
				highp11 = i+1;
			}
			if (oneFaces[i] == 3)
			{
				p1 += 3;
				highp1 = i+1;
			}

			if (twoFaces[i] == 1)
				highp22 = i+1;
			if (twoFaces[i] == 2)
			{
				p2 += 2;
				highp21 = i+1;
			}
			if (twoFaces[i] == 3)
			{
				p2 += 3;
				highp2 = i+1;
			}
		}
		if (p1 == 5 || p2 == 5)
		{
			if (highp1 > highp2)
			{
				//cout << "Full house - player one wins" << endl;
				playerOneWins++;
			}
			else if (highp2 > highp1)
			{
				//cout << "Full house - player two wins" << endl;
				playerTwoWins++;
			}
			else
			{
				if (highp11 > highp21)
				{
					//cout << "Full house - player one wins" << endl;
					playerOneWins++;
				}
				else if (highp21 > highp11)
				{
					//cout << "Full house - player two wins" << endl;
					playerTwoWins++;
				}
				else
				{
					if (highp12 > highp22)
					{
						//cout << "Full house - player one wins" << endl;
						playerOneWins++;
						continue;
					}
					else 
					{
						//cout << "Full house - player two wins" << endl;
						playerTwoWins++;
						continue;
					}
				}
			}
			continue;
		}

		// Flush
		if (oneSameSuites && twoSameSuites)
		{
			for (int j = 12; j >= 0; j--)
			{
				if (oneFaces[j] == twoFaces[j])
					continue;
				if (oneFaces[j] > twoFaces[j])
				{
					//cout << "Flush - player one wins" << endl;
					playerOneWins++;
				}
				else
				{
					//cout << "Flush - player two wins" << endl;
					playerTwoWins++;
				}
				break;
			}
		}
		else if (oneSameSuites)
		{
			//cout << "Flush - player one wins" << endl;
			playerOneWins++;
			continue;
		} 
		else if (twoSameSuites)
		{
			//cout << "Flush - player two wins" << endl;
			playerTwoWins++;
			continue;
		}

		// Straight
		if (oneConsecVal && twoConsecVal)
		{
			for (int j = 12; j >= 0; j--)
			{
				if (oneFaces[j] == twoFaces[j])
					continue;
				if (oneFaces[j] > twoFaces[j])
				{
					//cout << "Straight - player one wins" << endl;
					playerOneWins++;
				}
				else
				{
					//cout << "Straight - player two wins" << endl;
					playerTwoWins++;
				}
				break;
			}
		}
		else if (oneConsecVal)
		{
			//cout << "Straight - player one wins" << endl;
			playerOneWins++;
			continue;
		}
		else if (twoConsecVal)
		{
			//cout << "Straight - player two wins" << endl;
			playerTwoWins++;
			continue;
		}

		// Three of a kind
		p1 = p2 = 0;
		highp1 = highp2 = 0;
		for (int i = 0; i < 13; i++)
		{
			if (oneFaces[i] == 3)
				p1 = i+1;
			if (twoFaces[i] == 3)
				p2 = i+1;
			if (oneFaces[i] == 1)
				highp1 = i+1;
			if (twoFaces[i] == 1)
				highp2 = i+1;
		}
		if (p1 != 0 || p2 != 0)
		{
			if (p1 > p2)
			{
				//cout << "Three of a kind - player one wins" << endl;
				playerOneWins++;
			}
			else if (p2 > p1)
			{
				//cout << "Three of a kind - player two wins" << endl;
				playerTwoWins++;
			}
			else
			{
				if (highp1 > highp2)
				{
					//cout << "Three of a kind - player one wins" << endl;
					playerOneWins++;
				}
				else
				{
					//cout << "Three of a kind - player two wins" << endl;
					playerTwoWins++;
				}
			}
			continue;
		}


		// Two Pairs
		p1 = p2 = 0;
		highp1 = highp2 = 0;
		highp11 = highp21 = 0;
		highp12 = highp22 = 0;
		for (int i = 0; i < 13; i++)
		{
			if (oneFaces[i] == 2)
			{
				p1 += 2; 
				if (highp11 == 0)
					highp11 = i+1;
				else
					highp1 = i+1;
			}
			if (twoFaces[i] == 2)
			{
				p2 += 2;
				if (highp21 == 0)
					highp21 = i+1;
				else
					highp2 = i+1;
			}
			if (oneFaces[i] == 1)
				highp12 = i;
			if (twoFaces[i] == 1)
				highp22 = i;
		}
		if (p1 == 4 || p2 == 4)
		{
			if (highp1 > highp2)
			{
				//cout << "Two pairs - player one wins" << endl;
				playerOneWins++;
			}
			else if (highp2 > highp1)
			{
				//cout << "Two pairs - player two wins" << endl;
				playerTwoWins++;
			}
			else
			{

			}
			continue;
		}

		// One Pair
		p1 = p2 = 0;
		for (int i = 0; i < 13; i++)
		{
			if (oneFaces[i] == 2)
				p1 = i+1;
			if (twoFaces[i] == 2)
				p2 = i+1;
		}
		if (p1 != 0 || p2 != 0)
		{
			if (p1 > p2)
			{
				//cout << "One pair - player one wins" << endl;
				playerOneWins++;
			}
			else if (p2 > p1)
			{
				//cout << "One pair - player two wins" << endl;
				playerTwoWins++;
			}
			else
			{
				for (int j = 13; j >= 0; j--)
				{
					if (oneFaces[j] == twoFaces[j])
						continue;
					if (oneFaces[j] > twoFaces[j])
					{
						//cout << "One pair - player one wins" << endl;
						playerOneWins++;
					}
					else 
					{
						//cout << "One pair - player two wins" << endl;
						playerTwoWins++;
					}
					break;
				}
			}
			continue;
		}

		// High Card
		for (int i = 12; i >= 0; i--)
		{
			if (oneFaces[i] == twoFaces[i])
				continue;
			if (oneFaces[i] > twoFaces[i])
			{
				//cout << "High card - player one wins" << endl;
				playerOneWins++;
			}
			else
			{
				//cout << "High card - player two wins" << endl;
				playerTwoWins++;
			}
			break;
		}
	}
	cout << "Numer of hands player one wins: " << playerOneWins << endl;
}