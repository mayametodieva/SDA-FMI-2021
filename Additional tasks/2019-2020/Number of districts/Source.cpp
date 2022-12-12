#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <list>
using namespace std;

void dfs(unordered_map<int, list<int>>& adj, vector<bool>& visited, int from) {
    visited[from] = 1;

    for (auto it : adj[from]) {
        if (!visited[it])
        {
            dfs(adj, visited, it);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int Q;

    cin >> Q;

    while (Q--)
    {
        int vert, edgs, from, to;

        cin >> vert >> edgs;

        unordered_map<int, list<int>> adj;

        vector<bool> visited(vert);

        for (int i = 0; i < edgs; i++)
        {
            cin >> from >> to;
            adj[from].push_back(to);
            adj[to].push_back(from);
        }
        int components = 0;

        for (int i = 0; i < vert; i++)
        {
            if (!visited[i])
            {
                dfs(adj, visited, i);
                components++;
            }
        }
        
        printf("%d ", components);
    }

    return 0;
}