#pragma once
#include "probs.h"

void prob27()
{
	int a = 1;
	int b = 41;
	bool prime = true;
	int no = 0;
	int n = 0;
	while (prime)
	{
		no = n * n + a * n + b;
		prime = isPrime(no);
		n++;
	}
	printf("%d\n", n);
}