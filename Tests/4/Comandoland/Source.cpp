#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;


int main() {

    int N;

    cin >> N;

    priority_queue<int, vector<int>, greater<int>> vals;

    for (int i = 0; i < N; i++)
    {
        int num;

        cin >> num;

        if (vals.empty())
        {
            if (num == -1)
            {
                continue;
            }
            else
            {
                vals.push(num);
            }
        }
        else
        {
            if (num == -1)
            {
                printf("%d ", vals.top());
                vals.pop();
            }
            else
            {
                vals.push(num);
            }
        }
    }

    return 0;
}