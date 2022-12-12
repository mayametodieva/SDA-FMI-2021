#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <tuple>
#include <algorithm>
using namespace std;

int main() {

    int N, left, right, x = 0, y = 0;

    cin >> N;

    vector<tuple<int, int, int>> tree(N);

    tree[0] = make_tuple(0, x, y);

    for (int i = 0; i < N; i++)
    {
        cin >> left >> right;
        if (left != -1)
        {
            get<0>(tree[left]) = left;
            get<1>(tree[left]) = get<1>(tree[i]) - 1;
            get<2>(tree[left]) = get<2>(tree[i]) - 1;
        }
        if (right != -1)
        {
            get<0>(tree[right]) = right;
            get<1>(tree[right]) = get<1>(tree[i]) + 1;
            get<2>(tree[right]) = get<2>(tree[i]) - 1;
        }
    }

    sort(tree.begin(), tree.end(), [](tuple<int, int, int> const& t1, tuple<int, int, int> const& t2) {
        if (get<1>(t1) != get<1>(t2))
            return get<1>(t1) < get<1>(t2);
        else
        {
            if (get<2>(t1) != get<2>(t2))
                return get<2>(t1) > get<2>(t2);
            else
                return get<0>(t1) < get<0>(t2);}});

    cout << get<0>(tree[0]) << " ";

    for (long long i = 1; i < N; i++)
    {
        if (get<1>(tree[i]) != get<1>(tree[i - 1]))
        {
            cout << get<0>(tree[i]) << " ";
        }
    }

    return 0;
}
