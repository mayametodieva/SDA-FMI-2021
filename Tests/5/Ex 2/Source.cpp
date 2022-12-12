#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;


int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

     int N;

    cin >> N;

    unordered_map<int, int> nums;

    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;

        nums[num]++;
    }

    int sum = 0;

    auto it = nums.begin();

    while (it != nums.end())
    {
        if (it->second % 2 != 0)
        {
            sum += it->first * it->second;
        }
        it++;
    }

    printf("%d", sum);

    return 0;
}
