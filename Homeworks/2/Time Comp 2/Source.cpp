#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;


#pragma warning(disable:4996)


string convertString(long long stamp)
{
	string convString = "";
	if (stamp <= 9)
	{
		convString += "0";
	}
	return convString + to_string(stamp);
}

vector<long long> sortAndgetIndexes(vector<string> stamps, int N) {
	vector<long long> indexes;
	for (int i = 0; i < N; i++)
	{
		indexes.push_back(i);
	}

	sort(indexes.begin(), indexes.end(), [&](long long i, long long j) {
		if (stamps[i] == stamps[j])
		{
			return i < j;
		}
		return (string(stamps[i]) <= string(stamps[j]));
	});

	reverse(indexes.begin(), indexes.end());
	return indexes;
}

int main() {

	long long N;

	cin >> N;

	vector<string> stamps;

	for (long long i = 0; i < N; i++)
	{
		long long hours, minutes, seconds, days, months, years;

		scanf("%d:%d:%d %d.%d.%d", &hours, &minutes, &seconds, &days, &months, &years);

		string strHours = convertString(hours), strMinutes = convertString(minutes), 
			strSeconds = convertString(seconds), strDays = convertString(days), 
			strMonths = convertString(months), strYears = convertString(years);
	
		stamps.push_back(strYears + " " + strMonths + " " + strDays + " " + strHours + " " + strMinutes + " " + strSeconds);
	}

	vector<long long> indexes = sortAndgetIndexes(stamps, N);

	for (int i = 0; i < N; i++)
	{
		cout << indexes[i] + 1 << "\n";
	}


	return 0;
}