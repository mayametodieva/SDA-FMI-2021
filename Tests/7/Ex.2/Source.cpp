#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include<tuple>
using namespace std;

bool vis[10000][10000]{0};
vector<tuple<int, int, int>> adj;
unordered_set<int> unlucky;
int Q, vert;

void valid() {
    for (int i = 0; i < Q; i++)
    {
        cin >> vert;

        bool isValid = 1;

        vector<int> path(vert);

        for (int j = 0; j < vert; j++)
        {
            cin >> path[j];
        }

        for (int j = 0; j < vert - 1; j++)
        {
            if (vis[path[j]][path[j + 1]] == 0)
            {
                isValid = 0;
                break;
            }
        }

        if (isValid) {
            printf("1");
        }

        else {
            printf("0");
        }

    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, K;

    cin >> N >> M;

    int from, to, val;

    for (int i = 0; i < M; i++)
    {
        cin >> from >> to >> val;

        adj.push_back({ from,to,val });
    }

    cin >> K;

    int num;
    for (int i = 0; i < K; i++)
    {
        cin >> num;
        unlucky.insert(num);
    }

    for (int i = 0; i < M; i++)
    {
        if (unlucky.count(get<2>(adj[i])) == 0)
        {
            vis[get<0>(adj[i])][get<1>(adj[i])] = 1;
        }
    }

    cin >> Q;

    valid();

    return 0;
}

