#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int idx[122];

int main() {

    string word;

    cin >> word;

    for (long long i = 0; i < word.size(); i++)
    {
        int current = int(word[i]);
        idx[current]++;
    }

    for (int i = 0; i < word.size(); i++)
    {
        if (idx[int(word[i])] == 1)
        {
            cout << i << " ";
        }
    }

    //1222ioopogk

    return 0;
}