#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

void splitAndAdd(int num, set<int>& fins) {
    int i = num;

    while (i > 0)
    {
        i = (i - 1) & num;
        fins.insert(i);
    }
}

int main() {
    int N;

    cin >> N;

    set<int> finals;

    for (int i = 0; i < N; i++)
    {
        int num;

        cin >> num;

        finals.insert(num);

        splitAndAdd(num, finals);
    }

    cout << finals.size();

    return 0;
}
