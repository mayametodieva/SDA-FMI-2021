#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;

    cin >> N;

    vector<tuple<long long, long long, long long>> nums;

    for (long long i = 0; i < N; i++)
    {
        long long first, second;
        cin >> first >> second;

        nums.push_back({ first, second, i });
    }

    sort(nums.begin(), nums.end());

    priority_queue <pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> trav;

    long long time = get<0>(nums[0]), i = 0;

    int size = N;

    while (size > 0)
    {
        while (i < N && time >= get<0>(nums[i]))
        {
            trav.push({ get<1>(nums[i]), get<2>(nums[i]) });
            i++;
        }
         
        time += trav.top().first;
        printf("%lld ", trav.top().second);

        trav.pop(); 

        if (trav.empty() && time < get<0>(nums[i]))
        {
            time = get<0>(nums[i]);
        }

        size--;
    }

    return 0;
}
