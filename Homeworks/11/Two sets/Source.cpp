#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <list>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <climits>
using namespace std;

unordered_map<int, list<pair<int, int>>> ways;
vector<int> distances(100001, INT_MAX);

void findShortestWay(int node) {

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> trav;

    distances[node] = 0;
    trav.push({ 0,node });

    while (!trav.empty())
    {
        int parent = trav.top().second, cost = trav.top().first;
        trav.pop();

        if (cost > distances[parent])
        {
            continue;
        }

        for (auto it : ways[parent]) {
            if (distances[it.first] > cost + it.second)
            {
                distances[it.first] = cost + it.second;
                trav.push({ distances[it.first], it.first });
            }
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int verticies, edges, from, to, weight;

    cin >> verticies >> edges;

    for (int i = 0; i < edges; i++)
    {
        cin >> from >> to >> weight;

        ways[from].push_back({ to, weight });
        ways[to].push_back({ from, weight });
    }

    int numberOfFirstSeq;
    cin >> numberOfFirstSeq;

    for (int i = 0; i < numberOfFirstSeq; i++)
    {
        int num;
        cin >> num;

        ways[verticies].push_back({ num, 0 });
        ways[num].push_back({ verticies, 0 });
    }

    int numberOfSecondSeq;
    cin >> numberOfSecondSeq;

    queue<int>queries;
    for (int i = 0; i < numberOfSecondSeq; i++)
    {
        int num;
        cin >> num;

        queries.push(num);
    }

    findShortestWay(verticies);

    while (!queries.empty())
    {
        printf("%d\n", distances[queries.front()]);
        queries.pop();
    }

    return 0;
}
