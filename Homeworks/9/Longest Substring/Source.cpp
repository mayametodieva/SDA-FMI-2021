#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {

    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string first, second;

    cin >> first >> second;

    long long firstSize = first.size(), secondSize = second.size();

    long long** table = new long long *[firstSize + 1];

    for (long long i = 0; i <= firstSize; i++)
    {
        table[i] = new long long[secondSize + 1];
    }

    for (long long i = 0; i <= firstSize; i++)
    {
        table[i][0] = 0;
    }

    for (long long i = 0; i <= secondSize; i++)
    {
        table[0][i] = 0;
    }

    long long counter = 0;
    for (long long i = 1; i <= firstSize; i++)
    {
        for (long long j = 1; j <= secondSize; j++)
        {
            if (first[i - 1] == second[j - 1])
            {
                table[i][j] = table[i - 1][j - 1] + 1;

                if (counter < table[i][j])
                {
                    counter = table[i][j];
                }
            }
            else {
                table[i][j] = 0;
            }     
        }
    }

    printf("%lld", counter);
    return 0;
}