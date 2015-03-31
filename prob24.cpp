#include "probs.h"

int perm[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
void swap(int i, int j)
{
	int temp = perm[i];
	perm[i] = perm[j];
	perm[j] = temp;
}

void prob24()
{
	int cnt = 1;
	int lmt = 1000000;
	int noElem = 10;
	int i = 0;
	int j = 0;
	while (cnt < lmt)
	{
		i = noElem - 1;
		j = noElem;
		while (perm[i - 1] >= perm[i])
			i--;
		while (perm[j - 1] <= perm[i-1])
			j--;
		swap(i - 1, j - 1);

		i++;
		j = noElem;
		while (i < j)
		{
			swap(i - 1, j - 1);
			i++, j--;
		}

		cnt++;
	}

	for (int i = 0; i < noElem; i++)
	{
		printf("%d", perm[i]);
	}
}