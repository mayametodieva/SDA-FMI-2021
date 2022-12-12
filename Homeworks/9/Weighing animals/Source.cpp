#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <tuple>
using namespace std;

int main() {

    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long N, K;

    cin >> N >> K;

    vector<long long> nums(N);



    for (long long i = 0; i < N; i++)
    {
        cin >> nums[i];
    }

    unordered_map<long long, long long> numberOfNums, triples;

    long long i = 0, numberOfTriples = 0;

    while (i < N)
    {
        if (nums[i] % K == 0)
        {
            numberOfTriples += triples[nums[i] / K];
            triples[nums[i]] += numberOfNums[nums[i] / K];
        }
        numberOfNums[nums[i]]++;
        i++;
    }

    printf("%lld", numberOfTriples);

    return 0;
}