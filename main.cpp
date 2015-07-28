#pragma once
#include "probs.h"
#include <time.h>

int main()
{
	clock_t startTime = clock();
	prob69();
	cout << "\n\nTotal run time: " << double(clock() - startTime) / (double)CLOCKS_PER_SEC * 1000<< " milli seconds." << endl;

	cout << "Hit enter to exit" << endl;
	getchar();
}