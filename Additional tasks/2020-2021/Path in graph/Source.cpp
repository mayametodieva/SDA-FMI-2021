#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <list>
#include <unordered_map>
using namespace std;

unordered_map<int, list<int>> adj;
bool visited[1000000];
int components[1000000];

void dfs(int from, int cmp) {
    visited[from] = 1;
            components[from] = cmp;
    for (auto it : adj[from]) {
        if (!visited[it]) {
        

            dfs(it, cmp);
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int vert, edgs;

    cin >> vert >> edgs;

    int from, to;

    for (int i = 0; i < edgs; i++)
    {
        cin >> from >> to;
        adj[from].push_back(to);
        adj[to].push_back(from);
    }

    int cmp = 0;
    for (int i = 0; i < vert; i++)
    {
        if (!visited[i])
        {
            dfs(i, cmp);
            cmp++;
        }      
    }

    int k;

    cin >> k;

    for (int i = 0; i < k; i++)
    {
        cin >> from >> to;

        if (components[from] == components[to])
        {
            printf("1 ");
        }
        else
        {
            printf("0 ");
        }
    }

    return 0;
}