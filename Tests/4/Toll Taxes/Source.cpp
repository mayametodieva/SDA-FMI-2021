#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;

    cin >> N;

    cin >> K;

    priority_queue<pair<string, int>, vector<pair<string, int>>, greater<pair<string, int>>> couples;

    priority_queue<string, vector<string>, greater<string>> vals;

    string city;

    long long val;

    for (int i = 0; i < N; i++)
    {
        cin >> city >> val;

        couples.push({ city, val });
    }

    for (int i = 0; i < K; i++)
    {
        cin >> city;

        vals.push(city);
    }

    int sum = 0;

    while (!vals.empty())
    {
        if (vals.top() == couples.top().first)
        {
            sum += couples.top().second;
            vals.pop();
            couples.pop();
        }
        else
        {
            couples.pop();
        }

        if (vals.empty() || couples.empty())
        {
            break;
        }
    }

    printf("%lld", sum);


    return 0;
}
