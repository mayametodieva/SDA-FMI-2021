#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int countSymbols(string arr, char symbol) {
	int counter = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i] == symbol)
		{
			counter++;
		}
	}
	return counter;
}

int findFirstIndex(string arr, char symbol) {
	int index = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i] == symbol)
		{
			index = i;
			break;
		}
	}
	return index;
}

int findLastIndex(string arr, char symbol) {
	int index = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i] == symbol)
		{
			index = i;
		}
	}
	return index;
}

vector<int> findDistance(string arr, char symbol) {

	vector<int> distance, distance1, distance2 = {};

	int symbolsCount = countSymbols(arr, symbol);

	if (symbolsCount == 0)
	{
		for (int i = 0; i < arr.size(); i++)
		{
			distance.push_back(0);
		}
	}
	else {
		int size = arr.size();

		for (int i = 0, v = 1; i < size; i++, v++)
		{
			if (arr[i] == symbol)
			{
				distance1.push_back(0);
				v = 0;
			}
			else {
				distance1.push_back(v);
			}
		}

		for (int i = size - 1, v = 1; i >= 0; i--, v++)
		{
			if (arr[i] == symbol)
			{
				distance2.push_back(0);
				v = 0;
			}
			else {
				distance2.push_back(v);
			}
		}

		reverse(distance2.begin(), distance2.end());

		int lastIndex = findLastIndex(arr, symbol);
		int firstIndex = findFirstIndex(arr, symbol);

		for (int i = 0; i < firstIndex; i++)
		{
			distance.push_back(distance2[i]);
		}

		for (int i = firstIndex; i < lastIndex; i++)
		{
			if (distance1[i] < distance2[i])
			{
				distance.push_back(distance1[i]);
			}
			else
			{
				distance.push_back(distance2[i]);
			}
		}

		for (int i = lastIndex; i < size; i++)
		{
			distance.push_back(distance1[i]);
		}
	}

	return distance;
}

int main() {
	string arr;

	cin >> arr;

	char symbol;

	cin >> symbol;

	vector<int> distance = findDistance(arr, symbol);

	for (int i = 0; i < distance.size(); i++)
	{
		cout << distance[i] << " ";
	}

	return 0;
}