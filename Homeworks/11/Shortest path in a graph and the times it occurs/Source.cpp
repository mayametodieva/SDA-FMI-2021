#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <queue>
#include <climits>
#include <list>
#include <algorithm>
using namespace std;

struct object {
    long long minimalDistance = LLONG_MAX;
    long long numberOfOccs = 0;
};

const long long N = 100001;

const long long MOD = 1000000007;

vector<object> vals(N);
vector<list<pair<long long, long long>>> children(N);

void findShortestPath(long long node) {
    vals[node].minimalDistance = 0;
    vals[node].numberOfOccs = 1;

    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> trav;

    trav.push({ 0, node });

    while (!trav.empty())
    {
        long long parent = trav.top().second, parentsCost = trav.top().first;

        if (parentsCost > vals[parent].minimalDistance)
        {
            trav.pop();
            continue;
        }

        for (auto it : children[parent])
        {
            long long child = it.first, childsCost = it.second;

            if (vals[child].minimalDistance == parentsCost + childsCost)
            {
                vals[child].minimalDistance = parentsCost + childsCost;
                vals[child].numberOfOccs = (vals[child].numberOfOccs + vals[parent].numberOfOccs) % MOD;
            }
            else if (vals[child].minimalDistance > parentsCost + childsCost) {
                vals[child].minimalDistance = parentsCost + childsCost;
                vals[child].numberOfOccs = vals[parent].numberOfOccs % MOD;
                trav.push({ vals[child].minimalDistance , child });
            }
        }
        trav.pop();
    }
}
int main() {

    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long verticies, edges, from, to;

    long long cost;

    cin >> verticies >> edges;

    for (long long i = 0; i < edges; i++)
    {
        cin >> from >> to >> cost;
        children[from].push_back({ to, cost });
    }

    findShortestPath(1);

    if (vals[verticies].numberOfOccs == 0)
    {
        printf("%d %d", -1, 0);
    }
    else
    {
        printf("%lld %lld", vals[verticies].minimalDistance, vals[verticies].numberOfOccs % MOD);
    }

    return 0;
}
