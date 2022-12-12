#include<iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <list>
#include <unordered_map>
#include <climits>
#include <queue>
using namespace std;

const int N = 100000;
vector<pair<int, int>> adj[N];
vector<int> dist;

void Djikstra(int start) {
	dist.assign(N, INT_MAX);

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	dist[start] = 0;
	pq.push({ 0, start });

	while (!pq.empty())
	{
		int mommy_pos = pq.top().second, mommy_cost = pq.top().first;
		pq.pop();

		if (mommy_cost > dist[mommy_pos]) continue;

		for (auto baby : adj[mommy_pos])
		{
			int baby_pos = baby.first, baby_cost = baby.second, newDist = mommy_cost + baby_cost;

			if (dist[baby_pos] > newDist)
			{
				dist[baby_pos] = newDist;
				pq.push({ newDist, baby_pos });
			}
		}
	}
}

int main() {

	int vert, edgs;

	cin >> vert >> edgs;

	int from, to, weight;

	for (int i = 0; i < edgs; i++)
	{
		cin >> from >> to >> weight;
		adj[from].push_back({ to, weight });
		adj[to].push_back({ from, weight });
	}

	cin >> from;

	Djikstra(from);

	for (int i = 1; i < vert + 1; i++)
	{
		if (i == from)
		{
			continue;
		}

		if (dist[i] == 0)
		{
			cout << -1 << " ";
		}
		cout << dist[i] << " ";
	}

	return 0;
}