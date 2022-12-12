#include<iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <list>

using namespace std;

vector<tuple<long long, long long, long long, long long, long long>> edges;
long long parent[1000000], depth[1000000], vert, edg;

void init() {
	for (long long i = 0; i < vert; i++)
	{
		parent[i] = i;
		depth[i] = 0;
	}
}

long long findRoot(long long node) {
	if (node == parent[node])
		return node;
	return parent[node] = findRoot(parent[node]);
}

void unite(long long from, long long dest) {
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
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> vert >> edg;
	long long from, to, cost, value;
	for (int i = 0; i < edg; i++)
	{
		cin >> from >> to >> cost >> value;
		edges.push_back({ cost, value, from, to, i + 1 });

	}

	init();

	sort(edges.begin(), edges.end(), [](tuple<long long, long long, long long, long long, long long> const& t1, tuple<long long, long long, long long, long long, long long> const& t2 ) {
		if (get<0>(t1) == get<0>(t2))
		{
			return get<1>(t1) > get<1>(t2);
		}
		return (get<0>(t1) < get<0>(t2));
		});

	for (long long i = 0; i < edg; i++)
	{
		from = get<2>(edges[i]);
		to = get<3>(edges[i]);

		if (findRoot(from) != findRoot(to))
		{
			unite(from, to);
			printf("%d\n", get<4>(edges[i]));
		}	
	}

	return 0;
}
