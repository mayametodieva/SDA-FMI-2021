#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;

    cin >> N;

    set<int> vals;

    int num;
    for (int i = 0; i < N; i++)
    {
        cin >> num;
        vals.insert(num);
    }

    for (auto it : vals) {
        printf("%d ", it);
    }

    return 0;
}
