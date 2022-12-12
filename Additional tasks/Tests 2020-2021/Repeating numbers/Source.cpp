#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;


int main() {
    
    int N, M;

    cin >> N;

    set<int> first, second;
    int num;
    for (size_t i = 0; i < N; i++)
    { 
        cin >> num;

        first.insert(num);
    }

    cin >> M;

    for (int i = 0; i < M; i++)
    {
        cin >> num;

        second.insert(num);
    }

    int sum = 0;

    for (auto it: first)
    {
        if (second.count(it))
        {
            sum += it;
        }
    }

    printf("%d", sum);

    return 0;
}
