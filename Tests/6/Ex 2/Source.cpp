#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <queue>
using namespace std;

unordered_map <int, list<int>> neighbours;

vector<bool> visited(500000, false);

int dfs(int node) {
    visited[node] = true;
    int v = 1;
    for (auto child : neighbours[node])
        if (!visited[child])
            v += dfs(child);
    return v;
}

int main() {
    int verticies, edges;

    cin >> verticies >> edges;

    vector<int> towns;

    for (int i = 0; i < edges; i++)
    {
        int from, to;
        cin >> from >> to;
        neighbours[from].push_back(to);
        neighbours[to].push_back(from);
        towns.push_back(from);
    }

    for (auto it : towns) {
        if (!visited[it])
        {
            cout << dfs(it);
        }
    }
    return 0;
}
