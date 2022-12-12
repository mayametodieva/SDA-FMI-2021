#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;

#pragma warning(disable:4996)

vector<string> replaceSymbolsWithSpaces(vector<string> stamps, long long N) {
	for (long long i = 0; i < N; i++)
	{
		replace(stamps[i].begin(), stamps[i].end(), ':', ' ');
		replace(stamps[i].begin(), stamps[i].end(), '.', ' ');
	}
	return stamps;
}

vector<long long> convertStringToNumbers(string stamp) {
	stringstream ss(stamp);

	long long num;
	vector<long long> numbers;

	while (ss >> num)
	{
		numbers.push_back(num);
	}
	return numbers;
}

vector<vector<long long>> convertVector(vector<string> stamp, long long N) {
	vector<string> newStamp = replaceSymbolsWithSpaces(stamp, N);

	vector<vector<long long>> arr;

	for (long long i = 0; i < N; i++)
	{
		arr.push_back(convertStringToNumbers(newStamp[i]));
	}

	return arr;
}

string convertString(long long date)
{
	string convString = "";
	if (date <= 9)
	{
		convString += "0";
	}
	return convString + to_string(date);
}

vector<string> swapNumbers(vector<string> stamp, long long N) {
	vector<vector<long long>> convVector = convertVector(stamp, N);

	for (long long i = 0; i < N; i++)
	{
		swap(convVector[i][0], convVector[i][5]);
		swap(convVector[i][1], convVector[i][4]);
		swap(convVector[i][2], convVector[i][3]);
	}

	vector<string> newValues;

	for (long long i = 0; i < N; i++)
	{
		newValues.push_back(convertString(convVector[i][0]) + "/" + convertString(convVector[i][1]) + "/" + convertString(convVector[i][2])
			+ " " + convertString(convVector[i][3]) + ":" + convertString(convVector[i][4]) + ":" + convertString(convVector[i][5]));
	}

	for (int i = 0; i < N; i++)
	{
		cout << newValues[i] << endl;
	}
	cout << endl;
	return newValues;
}

vector<long long> sortIndexes(vector<string> stamp, long long N) {
	vector<string> stamps = swapNumbers(stamp, N);

	vector<long long> indexes;
	for (long long i = 0; i < N; i++)
	{
		indexes.push_back(i);
	}

	sort(indexes.begin(), indexes.end(), [&](long long i, long long j)
		{
			if (stamps[i] == stamps[j]) {
				return i < j;
			}
				return (string(stamps[i]) <= string(stamps[j]));});

	return indexes;
}

int main() {
	long long N;

	cin >> N;

	vector<string> stamps;

	for (long long i = 0; i < N; i++)
	{
		string first;
		cin >> first;

		string second;
		cin >> second;

		stamps.push_back(first + " " + second);
	}

	vector<long long> indexes = sortIndexes(stamps, N);

	for (long long i = 0; i < N; i++)
	{
		cout << indexes[i] + 1 << endl;
	}
	return 0;
}