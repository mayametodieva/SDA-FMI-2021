#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	map<int, int> counts;
	queue<int> trav;

	int N;
	cin >> N;

	int num;
	for (size_t i = 0; i < N; i++)
	{
		cin >> num;
		counts[num]++;

		if (counts[num] == 1)
		{
			trav.push(num);
		}
	}

	while (!trav.empty())
	{
		if (counts[trav.front()] == 1)
		{		
			printf("%d ", trav.front());
		}
		else if (counts[trav.front()] > 1)
		{
			counts[trav.front()] = 1;
			trav.push(trav.front());
		}
		trav.pop();
	}
	return 0;
}