#include<iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <list>
#include <climits>
#include <set>
#include <iterator>

using namespace std;

vector<tuple<int, int, int>> edges;
int parent[1000000], depth[1000000], vert, edg, counter;

void init() {
    for (int i = 0; i < vert; i++)
    {
        parent[i] = INT_MIN;
        depth[i] = 0;
        counter = 1;
    }
}

int findRoot(int node) {
    if (parent[node] == INT_MIN)
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

    counter++;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> vert >> edg;
    int from, to, cost;
    for (int i = 0; i < edg; i++)
    {
        cin >> from >> to >> cost;
        edges.push_back({ cost, --from, --to });
    }

    sort(edges.begin(), edges.end(), [](tuple<int, int, int> const& t1, tuple<int, int, int> const& t2) {
        return (get<0>(t1) < get<0>(t2)); });

    int min = 1, max = 30000;

    for (int i = 0; i < edg; i++)
    {
        int minCost = get<0>(edges[i]);
        init();

        for (int j = i; j < edg; j++)
        {
            from = get<1>(edges[j]);
            to = get<2>(edges[j]);
            cost = get<0>(edges[j]);

            if (findRoot(from) != findRoot(to))
            {
                unite(from, to);
                if (counter == vert)
                {
                    if (max - min > cost - minCost)
                    {
                        min = minCost;
                        max = cost;
                        break;
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
        if (counter < vert)
        {
            break;
        }
    }

    printf("%d %d", min, max);

    return 0;
}
