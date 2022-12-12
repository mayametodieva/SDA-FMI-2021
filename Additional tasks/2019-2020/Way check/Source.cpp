#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <set>
using namespace std;

int matrix[1000][1000]{0};

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int vert, edg;

    cin >> vert >> edg;

    int from, to, weight;
    for (int i = 0; i < edg; i++)
    {
        cin >> from >> to >> weight;
        matrix[from][to] = weight;
        matrix[to][from] = weight;
    }

    int k, sum = 0;

    cin >> k >> from;

    for (int i = 1; i < k; i++)
    {
        cin >> to;

        if (matrix[from][to] == 0)
        {
            sum = -1;
            continue;
        }
        else
        {
            sum += matrix[from][to];
        }
        from = to;
    }

    printf("%d", sum);

    return 0;
}