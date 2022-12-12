#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct cmp {
    int operator() (const pair<int, int>& first_p, const pair<int, int>& second_p) {
        return first_p.second > second_p.second;
    }
};

int* getTime(vector<pair<int, int>> vals, int N) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> trav;

    int i = 0, time = 0, waitTime = 0;

    int min = INT32_MIN, max = INT32_MAX;

    while (i < N && !trav.empty())
    {
        while (i < N && vals[i].first <= time) {
            trav.push(vals[i]);
            i++;
        }

        if (trav.empty())
        {
            trav.push(vals[i]);
            time = vals[i].first;
            i++;
        }
        else
        {
            waitTime += time + trav.top().second - trav.top().first;

            time += trav.top().second;
            trav.pop();

            if (min > waitTime)
            {
                min = waitTime;
            }
            if (max < waitTime)
            {
                max = waitTime;
            }
        }
    }

    int arr[2] = { min, max };

    return arr;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;

    cin >> N;

    vector<pair<int, int>> nums;

    for (int i = 0; i < N; i++)
    {
        int num;

        cin >> num;

        nums.push_back({ i, num });
    }

    int* arr = getTime(nums, N);

    cout << arr[0] << " " << arr[1];

    return 0;
}