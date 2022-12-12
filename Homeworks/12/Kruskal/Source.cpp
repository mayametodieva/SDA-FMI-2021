#include<iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <list>

using namespace std;

pair<int, pair<int, int>> edges[1000000];
int parent[1000000], depth[1000000], vert, edg;

void init() {
	for (int i = 0; i < vert; i++)
	{
		parent[i] = i;
		depth[i] = 0;
	}
}

int findRoot(int node) {
	if (node == parent[node])
		return node;
	return parent[node] = findRoot(parent[node]);
}

void unite(int from, int dest) {
	int firstRoot = findRoot(from), secondRoot = findRoot(dest);
	if (depth[firstRoot] > depth[secondRoot])
	{
		parent[secondRoot] = firstRoot;
	}
	else
	{
		parent[firstRoot] = secondRoot;
		if (depth[firstRoot] == depth[secondRoot])
		{
			depth[secondRoot]++;
		}
	}
}

int main() {
	cin >> vert >> edg;
	int from, to, cost;
	for (int i = 0; i < edg; i++)
	{
		cin >> from >> to >> cost;
		edges[i] = { cost, {from, to} };
	}

	init();

	int res = 0;
	sort(edges, edges + edg);

	for (int i = 0; i < edg; i++)
	{
		from = edges[i].second.first;
		to = edges[i].second.second;
		cost = edges[i].first;

		if (findRoot(from) != findRoot(to))
		{
			unite(from, to);
			res += cost;
		}
	}

	cout << res;

	return 0;
}


/*

6 10
0 1 4
0 2 4
0 3 2
1 2 1
2 4 5
2 5 2
0 4 3
0 5 3
1 4 1
1 5 1

*/