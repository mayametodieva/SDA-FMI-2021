#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <queue>
using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;

    cin >> N;

    queue<int> vals;
    set<int> trav;
    int ans = 0, prev = 0;
    int num;
    for (int i = 0; i < N; i++)
    {
        cin >> num;
        if (!trav.count(num))
        {
            trav.insert(num);
        }
        else
        {
            while (vals.front() != num)
            {
                trav.erase(vals.front());
                vals.pop();
            }
            vals.pop();
        }
        vals.push(num);
        int res = vals.size();
        ans = max(ans, res);
    }

    printf("%d", ans);
    return 0;
}
