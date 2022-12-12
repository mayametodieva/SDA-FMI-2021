#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct cmp {
    long long operator() (const pair<long long, long long>& first_p, const pair<long long, long long>& second_p) {
        return first_p.second > second_p.second;
    }
};

long long getTime(vector<pair<long long, long long>> vals, long long N) {
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, cmp> trav;

    long long i = 0, time = 0, waitTime = 0;

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
        }
    }

    waitTime /= N;

    return waitTime;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;

    cin >> N;

    vector<pair<long long, long long>> nums;

    for (long long i = 0; i < N; i++)
    {
        long long first, second;

        cin >> first >> second;

        nums.push_back({ first, second });
    }

    sort(nums.begin(), nums.end());
    
    printf("%lld", getTime(nums, N));

    return 0;
}