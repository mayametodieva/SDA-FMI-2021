#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
#include <set>
using namespace std;

struct cmp {
    bool operator() (const pair<long long, long long>& p1, const pair<long long, long long>& p2) {
        return p1.second > p2.second;
    }
};

int main() {
    long long N, K;

    cin >> N >> K;

    vector <tuple<long long, long long, long long>>nums;

    set<long long> operators;

    for (long long i = 0; i < N; i++)
    {
        long long first, second;

        cin >> first >> second;

        nums.push_back({ first, second, i % K });
        
        if (i < K)
        {
            operators.insert(i);
        }    
    }

    priority_queue<pair<long long, long long>, vector<pair< long long, long long>>, cmp> trav;

    vector<long long> vals(K);

    for (long long i = 0; i < N; i++)
    { 
        while (!trav.empty() && get<0>(nums[i]) >= trav.top().second)
        {
            operators.insert(trav.top().first);
            trav.pop();
        }

        if (operators.empty())
        {
            continue;
        }

        set<long long>::iterator it = operators.lower_bound(get<2>(nums[i]));
        long long sum = get<0>(nums[i]) + get<1>(nums[i]);

        if (it != operators.end()) {
            auto el = *it;
            trav.push({ el, sum });
            vals[el]++;
            operators.erase(el);
        } 
        else { 
            long long op = *operators.begin();
            trav.push({ op, sum });
            vals[op]++;
            operators.erase(operators.begin());
        }
    }

    long long mostWorking = 0;

    for (long long i = 0; i < K; i++)
    {
        if (mostWorking < vals[i])
        {
            mostWorking = vals[i];
        }
    }

    for (long long i = 0; i < K; i++)
    {
        if (vals[i] == mostWorking)
        {
            printf("%lld ", i);
        }
    }


    return 0;
}
