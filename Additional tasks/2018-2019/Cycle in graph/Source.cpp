#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <list>
using namespace std;

unordered_map<int, list<int>> adj;
vector<int> visited;
bool isThereACycle = false;

bool dfs(int from) {
    visited[from] = 1;

    for (auto it : adj[from])
    {
        if (!visited[it])
        {
            if (dfs(it)) {
                return true;
            }
        }
        else if (visited[it] == 1) {
            return true;
        }
    }

    visited[from] = 2;
    return false;
}

int main() {

    int Q;
    cin >> Q;

    for (int i = 0; i < Q; i++)
    {
        int vert, edgs;

        cin >> vert >> edgs;

        adj.clear();
        visited.assign(vert, 0);

        isThereACycle = false;

        for (int i = 0; i < edgs; i++)
        {
            int from, to, weight;

            cin >> from >> to >> weight;

            adj[--from].push_back(--to);
        }

        for (int i = 0; i < vert; i++)
        {
            if (!visited[i] && dfs(i))
            {
                isThereACycle = true;
                break;
            }
        }

        if (isThereACycle)
        {
            printf("true ");
        }
        else
        {
            printf("false ");
        }
    }

    return 0;
}