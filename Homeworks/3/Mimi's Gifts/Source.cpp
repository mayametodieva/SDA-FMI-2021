#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long findNumberOfPresents(long long number) {
	long long counter = 0;

	long long j = 0;

	for (j; j * j * j <= number; j++)
	{
		long long root = j * j * j;
	}

	long long i = j - 1;

	while(number > 0) {
		long long root = i * i * i;
		if (root <= number) {
			counter++;
			number -= root;
		}
		else
		{
			i--;
		}
	}

	return counter;
}


int main() {
	long long N;

	cin >> N;

	cout << findNumberOfPresents(N);

	return 0;
}