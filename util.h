#pragma once
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool isPrime(long no);

void isPrimeSieve(bool arr[], int n);

void getPrimeFac(int arr[], int N);

bool palindrome(long long no, int base);

double getpalindromeD(double no);

double factorial(double no);

void swap(int *i, int *j);

int getDigit(long no, int pos);

long gcd(long a, long b);

bool isPandigital(long no);

bool isSquare(long no);