#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include<list>
using namespace std;

void dfs(int v, bool* visited, unordered_map<int, list<int>>& adj) {
    visited[v] = 1;
    for (auto it : adj[v])
    {
        if (!visited[it])
        {
            dfs(it, visited, adj);
        }
    }
}

bool isConnected(int verticies, bool* visited, unordered_map<int, list<int>>& adj) {
    bool connected = true;

    int counter = 0;

    for (int i = 0; i < verticies; i++)
    {
        if (counter > 2)
        {
            connected = false;
            break;
        }
        else
        {
            if (!visited[i])
            {
                dfs(i, visited, adj);
                counter++;
            }
        }
    }

    return connected;
}


int main() {
    int Q, vert, edg, from, to;
    queue<string> res;

    cin >> Q;

    for (int i = 0; i < Q; i++)
    {
        unordered_map<int, list<int>> adj;
        bool visited[10000]{ 0 };
        vector<int> degs(10000, 0);

        cin >> vert >> edg;

        for (int j = 0; j < edg; j++)
        {
            cin >> from >> to;
            adj[from].push_back(to);
            adj[to].push_back(from);
            degs[from]++;
            degs[to]++;
        }

        if (adj.size() != vert || !isConnected(vert, visited, adj))
        {
            res.push("none");
            continue;
        }

        int odds = 0;
        for (int j = 0; j < vert + 1; j++)
        {
            if (degs[j] % 2 != 0)
            {
                odds++;
            }
        }

        if (odds == 0)
        {
            res.push("ecycle");
        }
        else if (odds == 2)
        {
            res.push("epath");
        }
        else
        {
            res.push("none");
        }
    }

    while (!res.empty())
    {
        cout << res.front() << "\n";
        res.pop();
    }

    return 0;
}