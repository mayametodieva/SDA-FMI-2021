#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct Tunnel {
    int to, c, w;

    Tunnel(int to, int w, int c = 0) : to(to), c(c), w(w) {}
};

typedef vector<vector<Tunnel>> Graph;

auto inp(int n, int m) {
    Graph g(n);
    while (m--) {
        int from, to, c, w;
        cin >> from >> to >> c >> w;
        g[from - 1].emplace_back(to - 1, w, c);
    }
    return g;
}

bool cmp(const Tunnel& a, const Tunnel& b) {
    return a.w > b.w;
}

constexpr int inf = 1'000'000'000;

vector<int> dijkstra(const Graph& g, int start, int maxAllowed) {
    priority_queue<Tunnel, vector<Tunnel>, decltype(&cmp)> q(&cmp);
    vector<int> dist(g.size(), inf);
    //vector<bool> isOut(g.size());
    dist[start] = 0;
    q.push({ start, 0 });
    while (!q.empty()) {
        int curr = q.top().to;
        q.pop();
        //if (isOut[curr]) continue;
        for (auto it : g[curr])
            if (it.c <= maxAllowed && dist[it.to] > dist[curr] + it.w) {
                dist[it.to] = dist[curr] + it.w;
                q.push({ it.to, dist[it.to] });
            }
        //isOut[curr] = true;
    }
    return dist;
}

int binarySearch(const Graph& g, int Min, int Max, int T) {
    int best = inf;
    while (Min <= Max) {
        int mid = (Min + Max) / 2;
        int dist = dijkstra(g, 0, mid).back();
        if (dist <= T) {
            best = mid;
            Max = mid - 1;
        }
        else
            Min = mid + 1;
    }
    return best != inf ? best : -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M, T;
    cin >> N >> M >> T;
    auto g = inp(N, M);
    cout << binarySearch(g, 1, 1'000'000, T) << endl;
}