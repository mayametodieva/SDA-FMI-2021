#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;

    cin >> N >> M;

    vector<int> nums;

    int num;

    for (int i = 0; i < N; i++)
    {
        cin >> num;
        nums.push_back(num);
    }

    sort(nums.begin(), nums.end());

    for (int i = 0; i < M; i++)
    {
        cin >> num;

        auto it = lower_bound(nums.begin(), nums.end(),num);
        int pos = it - nums.begin();

        printf("%d ", pos);
    }

    return 0;
}
