#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <iterator>
using namespace std;

long long getAns(map<long long, long long>::iterator val, set<long long> vals, map<long long, long long> m) {
    auto it = vals.find((*val).second);
    auto prevIt = prev(it);

    long long closestIdx = 0;

    while (*it - *prevIt <= 2)
    {
        auto el = m.find(*it);

        long long currentIdx = (*el).first;



        

        prevIt--;
    }
    return closestIdx;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, K;

    cin >> N >> K;

    map<long long, long long> nums;

    set<long long> orderedValues;

    for (long long i = 0; i < N; i++)
    {
        long long num;

        cin >> num;

        nums.insert({ i, num });

        orderedValues.insert(num);

    }

    /*for (long long i = 0; i < N; i++)
    {
        long long currentAns = -1;
        if (i-1 == -1)
        {
            printf("%lld ", currentAns);
        }
        else
        {
            long long j = i - 1;
            while (j >= 0) {
                if (j == 0)
                {
                    if (nums[i - 1] < nums[i] && nums[i] - nums[i - 1] <= K)
                    {
                        currentAns = j;
                        break;
                    }
                    else
                    {
                        break;
                    }
                }
                else if (nums[i - 1] < nums[i] && nums[i] - nums[i - 1] <= K) {
                    currentAns = j;
                    break;
                }
                j--;
            }
            printf("%lld ", currentAns);
        }
    }*/

    for (auto it = nums.begin(); it != nums.end(); it++)
    {
        long long currentAns = -1;

        auto inSet = orderedValues.find((*it).second);

        if (prevIt == nums.end())
        {
            printf("%lld ", currentAns);
        }
        else {

            while ((*prevIt).first >= 0)
            {
                if ((*prevIt).first == 0)
                {
                    if ((*prevIt).second < (*it).second && ((*it).second - (*prevIt).second) <= K) {
                        currentAns = (*prevIt).first;
                        break;
                    }
                    else
                    {
                        currentAns = -1;
                        break;
                    }
                }
                else if ((*prevIt).second < (*it).second && ((*it).second - (*prevIt).second) <= K)
                {
                    currentAns = (*prevIt).first;
                    break;
                }
                prevIt--;
            }
            printf("%lld ", currentAns);
        }
    }

    return 0;
}