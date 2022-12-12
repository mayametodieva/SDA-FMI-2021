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

    unordered_map<int, int> numberOfOrders;

    int num;
    for (int i = 0; i < N; i++)
    {
        cin >> num;

        numberOfOrders[num]++;
    }

    auto it = numberOfOrders.begin();

    int clients = 0, orders = 0;

    while (it != numberOfOrders.end())
    {
        if (it->second % 10 != 0)
        {
            clients++;
            orders += it->second % 10;
        }
        it++;
    }

    printf("%d %d", clients, orders);
    return 0;
}