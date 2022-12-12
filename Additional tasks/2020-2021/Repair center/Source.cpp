#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;


int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int ToBeRemoved, toBeTravered, queries, N, counter = 0;

    cin >> ToBeRemoved >> toBeTravered >> queries >> N;

    priority_queue<int, vector<int>, greater<int>> vals;

    int input;
    for (int i = 1; i <= N; i++)
    {
        cin >> input;

        vals.push(input);
        if (i % toBeTravered == 0)
        {
            int num = ToBeRemoved;
            while (num-- && !vals.empty())
            {
                printf("%d ", vals.top());
                vals.pop();
            }
            queries--;
        }
    }

    while (queries)
    {
        for (int i = 0; i < ToBeRemoved; i++)
        {
            printf("%d ", vals.top());
            vals.pop();
        }
        queries--;
    }

    return 0;
}
