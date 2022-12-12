#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    int num;
    vector<int> vals(N);

    for (int i = 0; i < N; i++)
    {
        cin >> vals[i];
    }

    int Q;
    cin >> Q;

    for (int i = 0; i < Q; i++)
    {
        cin >> num;

        auto low = lower_bound(vals.begin(), vals.end(), num);
        int pos = low - vals.begin();

        if (vals[pos] != num)
        {
            printf("%d\n", pos);
        }
        else
        {
            auto up = upper_bound(vals.begin(), vals.end(), num);
            int pos2 = up - vals.begin();

            printf("%d %d\n", pos, pos2);
        }
    }

    return 0;
}

