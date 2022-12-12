#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <list>
using namespace std;

unordered_map <int, list<int>> neighbours;
vector<bool> visited;

void bfs(int v)
{
     visited.assign(100000, false);
    queue<int> q;
    visited[v] = 1;
    q.push(v);

    while (!q.empty())
    {
        int current = q.front();
        q.pop();
        for (auto neighbour : neighbours[current])
        {
            if (!visited[neighbour])
            {
                visited[neighbour] = 1;
                q.push(neighbour);
            }
        }
    }
}

int main() {
    int verticies, edges;

    cin >> verticies >> edges;

    for (int i = 0; i < edges; i++)
    {
        int from, to;
        cin >> from >> to;
        neighbours[from].push_back(to);
        neighbours[to].push_back(from);
    }

    int K;
    cin >> K;

    bfs(1);

    for (int i = 0; i < K; i++)
    {
        int from, to;

        cin >> from >> to;

        if (!visited[to])
        {
            printf("%d ", 1);
        }
        else
        {
            printf("%d ", 0);
        }
        
    }

    return 0;
}