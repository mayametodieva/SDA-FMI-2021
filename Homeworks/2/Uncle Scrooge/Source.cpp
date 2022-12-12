#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//3 7 - 4 11 9 1

void mySwap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

int partition(int* arr, int l, int h) {
	int pi = arr[h];
	int i = l - 1;
	for (int j = l; j <= h - 1; j++)
	{
		if (arr[j] < pi)
		{
			i++;
			mySwap(arr[i], arr[j]);
		}
	}
	mySwap(arr[i + 1], arr[h]);
	return (i + 1);
}

void quickSort(int* arr, int l, int h) {

	if (l < h)
	{
		int pi = partition(arr, l, h);

		quickSort(arr, l, pi - 1);
		quickSort(arr, pi + 1, h);
	}
}

bool iSwholeArrayNegative(int* arr, int N) {
	int counter = 0;
	for (int i = 0; i < N; i++)
	{
		if (arr[i] < 0)
		{
			counter++;
		}
	}
	if (counter == N)
	{
		return true;
	}
	return false;
}

long findMinSum(int* arr, int N, int M) {

	long sum = 0;

	
	quickSort(arr, 0, N - 1);

	for (int i = 0; i < M; i++)
	{
		sum += arr[i];
	}

	if (iSwholeArrayNegative(arr, N))
	{
		sum = 0;
	}

	return sum;
}

int main() {
	int N;

	cin >> N;

	int* arr = new int[N];

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	int M;

	cin >> M;

	std::cout << findMinSum(arr, N, M);

	delete[] arr;
	return 0;
}