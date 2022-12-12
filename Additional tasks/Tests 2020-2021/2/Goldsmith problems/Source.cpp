#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;


int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;

    cin >> N;
    unordered_map<int, int> nums;

    int num;
    for (int i = 0; i < N; i++)
    {
        cin >> num;
        nums[num]++;

        if (nums[num] == 10)
        {
            nums.erase(num);
        }
    }

    int sum = 0;
    for (auto it: nums)
    {
        sum += it.second;
    }

    printf("%d %d", nums.size(), sum);

    return 0;
}
