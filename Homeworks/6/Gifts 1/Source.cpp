#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int M = 1000001;
vector<int> tree[M];

int findPresents(int counter, vector<int> values)
{
    int size = values.size();

    counter = size;

    for (int i = 0; i < size; i++)
    {
        if (tree[values[i]].size() > 0)
        {
            counter += findPresents(counter, tree[values[i]]);
        }
    }

    return counter;
}

int main()
{
    int N, parent, child;

    cin >> N;

    int size = N;

    size--;

    while (size)
    {
        cin >> parent >> child;
        tree[parent].push_back(child);
        size--;
    }

    for (int i = 0; i < N; i++)
    {
        int counter = 0;
        if (tree[i].size() > 0)
        {
            counter = findPresents(counter, tree[i]);
        }
        cout << counter << " ";
    }

    return 0;
}