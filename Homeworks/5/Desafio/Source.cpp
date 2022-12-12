#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

long long countDaysTillFinal(vector<long long>& players, long long N) {
    long long daysTillFinal = 0;

    stack<pair<long long, long long>> trav;
    trav.push(make_pair(0, 0));

    for (long long i = 1; i < N; i++)
    {
        long long currentDays = 1;
        while (!trav.empty()) {
            long long idx = trav.top().first;
            long long days = trav.top().second + 1;
            if (players[idx] < players[i])
            {
                break;
            }
            else
            {
                if (currentDays < days)
                {
                    currentDays = days;
                }
                trav.pop();
            }
        }
        if (trav.empty())
        {
            currentDays = 0;
        }
        if (daysTillFinal < currentDays)
        {
            daysTillFinal = currentDays;
        }
        trav.push(make_pair(i, currentDays));
    }

    if (daysTillFinal > 0)
    {
        return daysTillFinal;
    }
    else
    {
        return 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;

    cin >> N;

    vector<long long> players(N);

    for (long long i = 0; i < N; i++)
    {
        cin >> players[i];
    }

     printf("%lld ",countDaysTillFinal(players, N));
    
    return 0;
}
