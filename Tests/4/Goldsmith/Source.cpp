#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;


int main() {
    long long N;

    cin >> N;

    vector<int> nums;
    priority_queue<int, vector<int>, less<int>> trav;
    long long val;

    for (long long i = 0; i < N; i++)
    {
        cin >> val;

        nums.push_back(val);
        trav.push(val);
    }
    int comp = trav.top();
    trav.pop();

    bool isTrue = false;
    while (!trav.empty())
    {
        int sum = 0;
        int i = 0, j = 0;
        while (i < N)
        {
            sum = nums[j] + nums[i];

            if (comp == sum)
            {
                isTrue = true;
                break;
            }

            i++;
        }
        j++;
        comp = trav.top();
        trav.pop();
    }

    if (isTrue == true)
    {
        printf("true");
    }
    else
    {
        printf("false");
    }

    return 0;
}