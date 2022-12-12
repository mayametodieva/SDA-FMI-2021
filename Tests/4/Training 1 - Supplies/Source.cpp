#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
   
    int N;

    cin >> N;

    priority_queue<int, vector<int>, greater<int>> items;

    for (long long i = 0; i < N; i++)
    {
        int num;

        cin >> num;

        items.push(num);
    }

    int leftUsers = 1, leftItems = 0, currItems = 1;

    int comp = items.top();
    items.pop();

    while (!items.empty())
    {
        if (comp != items.top()) {
            if (currItems > 10 && currItems % 10 != 0)
            {
                leftItems += currItems % 10;
                leftUsers++;
            }
            else if (currItems < 10)
            {
                leftItems += currItems;
                leftUsers++;
            }
            if (items.empty())
            {
                break;
            }
            currItems = 1;
            comp = items.top();
            items.pop();
        }

        else {
            currItems++;
            items.pop(); 
            
            if (items.empty())
            {
                if (currItems % 10 != 0) {
                    leftItems += currItems % 10;
                }
            }
        }
    }

    printf("%d %d", leftUsers, leftItems);

    return 0;
}