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

    unordered_map<string, int> nums;

    vector<string> vals;

    for (int i = 0; i < N; i++)
    {
        string val;

        cin >> val;

        vals.push_back(val);

        nums[val]++;
    }

    for (int i = 0; i < N; i++)
    {
        printf("%d ",nums[vals[i]]);
    }
    
    return 0;
}