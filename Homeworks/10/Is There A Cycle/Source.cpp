#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <list>
using namespace std;

unordered_map<int, list<int>> vals;

void depthFirstSearch(vector<bool>& numberOfEdges, int num, bool& isThereACycle) {
    if (numberOfEdges[num])
    {
        isThereACycle = 1;
        return;
    }
    numberOfEdges[num] = 1;

    for (auto it : vals[num])
    {
        depthFirstSearch(numberOfEdges, it, isThereACycle);
    }

    numberOfEdges[num] = 0;
}

bool isThereACycle(unordered_map<int, list<int>> vals, vector<bool> numberOfEdges) {
    bool isCycle = false;

    for (int i = 0; i < vals.size(); i++)
    {
        if (!numberOfEdges[i])
        {
            depthFirstSearch(numberOfEdges, i, isCycle);
        }

    }
    return isCycle;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;

    cin >> N;

    int K, from, to, weight;

    for (int i = 0; i < N; i++)
    {
        cin >> K;

        vals.clear();

        vector<bool> numberOfEdges(10000, 0);

        for (int i = 0; i < K; i++)
        {
            cin >> from >> to >> weight;

            vals[--from].push_back(--to);
        }

        printf("%d ", isThereACycle(vals, numberOfEdges));
    }
    return 0;
}