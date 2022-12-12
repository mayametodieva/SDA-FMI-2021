#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <bitset>
#include <iterator>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;

    cin >> N;

    set<long long> nums;

    nums.insert(0);

    long long currentMin = 0;

    long long num;

    cin >> num;

    nums.insert(num);

    long long min = 0 ^ num;

    printf("%lld\n", min);

    for (long long i = 1; i < N; i++)
    {
        cin >> num;

        auto el = nums.insert(num);

        auto it = el.first;

        if (el.second == false)
        {
            printf("%lld\n", min);
        }
        else
        {
            if (next(it) == nums.end())
            {
                currentMin = min;
            }
            else
            {
                if (((*it) ^ *prev(it)) < (*next(it) ^ (*it)))
                {
                    currentMin = (*it) ^ *prev(it);
                }
                else
                {
                    currentMin = (*it) ^ *next(it);
                }
            }

            if (min > currentMin)
            {
                min = currentMin;
                printf("%lld\n", currentMin);
            }
            else
            {
                printf("%lld\n", min);
            }
        }
    }
    return 0;
}