#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <queue>
using namespace std;

unordered_map<int, list<int>> adj;
vector<int> visited;

set<int> to_track;

void bfs(int from) {
    visited[from]++;
    queue<int> trav;
    trav.push(from);

    while (!trav.empty())
    {
        int curr = trav.front();
        trav.pop();

        for (auto it : adj[curr]) {
            if (!visited[it] && !to_track.count(it))
            {
                visited[it] = visited[curr] + 1;
                trav.push(it);
            }
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
    }


    int K;

    cin >> K;

    queue<int> nums;

    int ans = 0;

    int num;
    for (int i = 0; i < K; i++)
    {
        cin >> num;
        to_track.insert(num);
        nums.push(num);
    }

    from = nums.front();
    nums.pop();

    to_track.erase(from);

    while (!nums.empty()) {
        visited.assign(vert, 0);

        to = nums.front();
        nums.pop();

        to_track.erase(to);

        bfs(from);

        ans += visited[to] - 1;

        if (!visited[to])
        {
            printf("-1");
            return 0;
        }   
        from = to;
    }

    printf("%d", ans);

    return 0;
}
