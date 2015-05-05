#include "probs.h"
#include <time.h>

int main()
{
	clock_t startTime = clock();
	prob23();
	cout << "\n\n" << double(clock() - startTime) / (double)CLOCKS_PER_SEC * 1000 << " milli seconds." << endl;

	int gc = getchar();
}