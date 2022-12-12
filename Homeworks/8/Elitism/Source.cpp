#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <iomanip>
using namespace std;

vector<double> getMedian(vector<double> vals) {
    priority_queue<double> increase;
    priority_queue<double, vector<double>, greater<double>> decrease;

    vector<double> res;

    for (auto n : vals)
    {
        if (increase.empty() || increase.top() > n)
        {
            increase.push(n);
        }
        else
        {
            decrease.push(n);
        }

        if (increase.size() > decrease.size() && increase.size() - decrease.size() > 1)
        {
            decrease.push(increase.top());
            increase.pop();
        }
        else if (increase.size() < decrease.size() && decrease.size() - increase.size() > 1)
        {
            increase.push(decrease.top());
            decrease.pop();
        }

        if (increase.size() > decrease.size())
        {
            res.push_back(increase.top());
        }
        else if (increase.size() < decrease.size())
        {
            res.push_back(decrease.top());
        }
        else
        {
            res.push_back((increase.top() + decrease.top()) / 2.0);
        }
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;

    cin >> N;

    vector<double> nums;

    for (int i = 0; i < N; i++)
    {
        double num;

        cin >> num;

        nums.push_back(num);
    }

    vector<double> res = getMedian(nums);

    for (auto n : res)
    {
        cout << fixed << setprecision(1) << n << "\n";
    }
    return 0;
}