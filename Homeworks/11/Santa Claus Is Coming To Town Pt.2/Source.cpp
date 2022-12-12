#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <queue>
#include <list>
using namespace std;

long k, verticies, edges;

struct tunnel
{
    long directory;
    long kilos;
    long time;
};

unordered_map<long, list<tunnel>> tunnels;

vector<long> getPossibleKilos(long node, long max)
{

    vector<long> distances(verticies + 1, LONG_MAX);

    priority_queue<pair<long, long>, vector<pair<long, long>>, greater<pair<long, long>>> trav;

    distances[node] = 0;
    trav.push({ 0, node });

    while (!trav.empty())
    {
        long parent = trav.top().second;
        trav.pop();

        for (auto it = tunnels[parent].begin(); it != tunnels[parent].end(); it++)
        {
            if (distances[it->directory] > distances[parent] + it->time && it->kilos <= max)
            {
                distances[it->directory] = distances[parent] + it->time;
                trav.push({ distances[it->directory], it->directory });
            }
        }
    }
    return distances;
}

long binary(long min, long max)
{
    long ans = LONG_MAX, mid = 0, last = 0;
    while (min <= max)
    {
        mid = min + (max - min) / 2;
        last = getPossibleKilos(1, mid)[verticies];
        if (last > k)
        {
            min = mid + 1;
        }
        else
        {
            ans = mid;
            max = mid - 1;
        }
    }

    if (ans != LONG_MAX)
    {
        return ans;
    }
    else
    {
        return -1;
    }
}

int main()
{

    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long from, to, kilos, timePerTunel;

    cin >> verticies >> edges >> k;

    for (int i = 0; i < edges; i++)
    {
        cin >> from >> to >> kilos >> timePerTunel;

        tunnels[from].push_back({ to, kilos, timePerTunel });
    }

    printf("%ld", binary(1, 1000001));
    return 0;
}