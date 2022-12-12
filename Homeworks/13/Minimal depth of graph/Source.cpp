#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <list>
#include <set>
#include <queue>
using namespace std;

queue<int> trav;
int degs[100000]{ 0 };

void checkAndinsertInQueue(int v) {
    if (degs[v] == 1)
    {
        trav.push(v);
    }
}

int main() {
    int N, from, to;
    unordered_map<int, list<int>> adj;
    cin >> N;

    for (int i = 0; i < N - 1; i++)
    {
        cin >> from >> to;
        adj[from].push_back(to);
        adj[to].push_back(from);

        degs[from]++;
        degs[to]++;
    }

    set<int> res;

    for (int i = 0; i < N; i++) 
        checkAndinsertInQueue(i);
    
    while (!trav.empty())
    {
        res.clear();
        int travSize = trav.size();

        for (int i = 0; i < travSize; i++)
        {
            for (auto it : adj[trav.front()]) {
                
                --degs[it];
                checkAndinsertInQueue(it);
            }
            res.insert(trav.front());
            trav.pop();
        }
    }

    for (auto i = res.begin(); i != res.end(); i++)
    {
        cout << *i << " ";
    }
    return 0;
}
