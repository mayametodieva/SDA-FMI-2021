#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <tuple>
using namespace std;

vector<tuple<double, int, int>> configVector(vector<pair<int, double>> arr, int N) {
	vector<tuple<double, int, int>> newVector;
	
	for (int i = 0; i < N; i++)
	{
		double sum = pow(arr[i].first, 2) / arr[i].second;
		
		newVector.push_back(make_tuple(sum, arr[i].first, i));
	}

	return newVector;
}

vector<int> getIndexes(vector<tuple<double, int, int>> params, int N) {

	sort(params.begin(), params.end(), [](tuple<double, int, int> const& t1, tuple<double, int, int> const& t2) {
		if (get<0>(t1) == get<0>(t2))
		{
			return get<1>(t1) > get<1>(t2);
		}
		return (get<0>(t1) > get<0>(t2)); });

	vector<int> indexes;

	for (int i = 0; i < N; i++)
	{
		indexes.push_back(get<2>(params[i]) + 1);
	}

	return indexes;
}

int main() {
	int N;

	cin >> N;

	vector<pair<int, double>> boys;

	for (int i = 0; i < N; i++)
	{
		double v1, v2;

		cin >> v1 >> v2;

		boys.push_back(make_pair(v1, v2));

	}

	vector<tuple<double, int, int>> newBoys = configVector(boys, N);

	vector<int> indexes = getIndexes(newBoys, N);

	for (int i = 0; i < N; i++)
	{
		cout << indexes[i] << " ";
	}

	return 0;
}