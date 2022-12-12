#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long closest(long long a, long long b, long long targetNum) {
	if (abs(targetNum - a) <= abs(targetNum - b))
	{
		return a;
	}
	return b;
}

long long binarySearch(long long* arr, long long size, long long targetNum) {

	long long left = 0;
	long long right = size - 1;
	long long mid = 0;

	if (targetNum <= arr[0])
	{
		return arr[0];
	}
	if (targetNum >= arr[size - 1])
	{
		return arr[size - 1];
	}

	while (left <= right)
	{
		mid = (left + right) / 2;

		if (arr[mid] == targetNum)
		{
			return arr[mid];
		}

		if (arr[mid] < targetNum)
		{
			if (mid < size - 1 && targetNum < arr[mid + 1])
			{
				return closest(arr[mid], arr[mid + 1], targetNum);
			}
			left = mid + 1;
		}
		else
		{
			if (mid > 0 && targetNum > arr[mid - 1])
			{
				return closest(arr[mid - 1], arr[mid], targetNum);
			}
			right = mid - 1;
		}
	}
	return arr[mid];

}


int main() {
	long long numberOfTopics;

	cin >> numberOfTopics;

	long long numberOfTeams;

	cin >> numberOfTeams;

	long long* topics = new long long[numberOfTopics];

	for (long long i = 0; i < numberOfTopics; i++)
	{
		cin >> topics[i];
	}

	long long* teams = new long long[numberOfTeams];

	for (long long i = 0; i < numberOfTeams; i++)
	{
		cin >> teams[i];
	}

	//for (int i = 0; i < numberOfTopics; i++)
	//{
	//	cout << topics[i] << " ";
	//}

	//cout << endl;

	//for (int i = 0; i < numberOfTeams; i++)
	//{
	//	cout << teams[i] << " ";
	//}

	//cout << endl;


	for (long long i = 0; i < numberOfTeams; i++)
	{
		cout << binarySearch(topics, numberOfTopics, teams[i]) << endl;
	}

	delete[] topics;
	delete[] teams;

	return 0;
}