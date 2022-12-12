//12
//1 2 3 5 6 9 12 7 14 11 13 1

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool isThereOne(int* arr, int size) {
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == 1)
		{
			return true;
		}
	}
	return false;
}

int findNumber(int* arr, int size) {

	sort(arr, arr + size);

	int missingNumber = 0;

	if (size == 0)
	{
		missingNumber = 1;
	}

	if (!isThereOne(arr, size))
	{
		missingNumber = 1;
	}
	else {
		for (int i = 0; i < size; i++)
		{
			if (arr[i] < 0)
			{
				continue;
			}
			if (arr[i + 1] > arr[i] + 1) {
				missingNumber = arr[i] + 1;
				break;
			}
			else if (arr[i] + 1 == arr[i + 1] && arr[i + 1] == arr[size - 1])
			{
				missingNumber = arr[i + 1] + 1;
			}
		}
	}
	
	return missingNumber;
}


int main() {

	int size;

	cin >> size;

	int* arr = new int[size];

	for (int i = 0; i < size; i++)
	{
		cin >> arr[i];
	}

	cout << findNumber(arr, size);	

	delete[] arr;

	return 0;
} 