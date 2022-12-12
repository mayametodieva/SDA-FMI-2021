#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

int parent[100000], depth[100000]{ 0 };
tuple<int, int, int> edges[500000];

int findRoot(int node) {
    if (parent[node] == node)
    {
        return node;
    }
    return parent[node] = findRoot(parent[node]);
}

void unite(int f, int s) {
    if (depth[f] < depth[s])
    {
        parent[f] = s;
    }
    else
    {
        parent[s] = f;
        if (depth[f] == depth[s])
        {
            depth[f]++;
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int vert, edgs;
    cin >> vert >> edgs;

    int from, to, weight;
    for (int i = 0; i < edgs; i++)
    {
        cin >> from >> to >> weight;

        edges[i] = { weight,from, to };
    }


    for (int i = 0; i < vert; i++)
    {
        parent[i] = i;
    }

    sort(edges, edges + edgs);
    int ans = 0;
    for (int i = edgs - 1; i >= 0; i--)
    {
        weight = get<0>(edges[i]);
        from = get<1>(edges[i]);
        to = get<2>(edges[i]);

        int f = findRoot(from), s = findRoot(to);

        if (f != s)
        {
            unite(f, s);
        }
        else
        {
            ans += weight;
        }
    }

    printf("%d", ans);

    return 0;
}
