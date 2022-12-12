#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include<list>
using namespace std;

int vert = 0, edg = 0;
queue<string> res;
int degs[10000]{ 0 };

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int Q;
    cin >> Q;
    int from = 0, to = 0;

    for (int i = 0; i < Q; i++)
    {

        cin >> vert >> edg;

        for (int j = 0; j < edg; j++)
        {
            cin >> from >> to;

            /*adj[--from].push_back(--to);
            adj[to].push_back(from);*/

            degs[from]++;
            degs[to]++;
        }

        /*if (!isConnected())
        {
            printf("none\n");
            adj.clear();
            visited.clear();
            degs.clear();
            continue;
        }*/

        int odds = 0;
        for (int j = 0; j < 10000; j++)
        {
            if (degs[i] % 2 != 0)
            {
                odds++;
            }
        }

        if (odds == 0)
        {
            res.push("ecycle\n");
        }
        else if (odds == 2)
        {
            res.push("epath\n");
        }
        else
        {
            res.push("none");
        }

        /*adj.clear();
        visited.assign(100000,0);
        degs.assign(100000,0);*/
    }

    while (!res.empty())
    {
        cout << res.front();
        res.pop();
    }
    
    return 0;
}
