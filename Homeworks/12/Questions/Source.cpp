#include <cmath>
#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

pair<int, int> edges[2000];
int parent[2000], depth[2000], vert, edg;

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
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> vert >> edg;
    int from, to;
    init();
    for (int i = 0; i < edg; i++)
    {
        cin >> from >> to;
        edges[i] = { from, to };
        unite(from, to);
    }

    int numberOfQueries, query;

    cin >> numberOfQueries;

    for (int i = 0; i < numberOfQueries; i++)
    {
        cin >> query >> from >> to;

        if (query == 1)
        {
            printf("%d",(findRoot(from) == findRoot(to)));
        }
        else
        {
            unite(from, to);
        }
    }

    return 0;
}