#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;


int main() {

    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long N;

    cin >> N;

    unordered_map<long long, vector<long long>> keys;

    vector<long long> doors;

    long long number;
    for (long long i = 0; i < N; i++)
    {
        cin >> number;

        keys[number].push_back(i);
    }

    for (long long i = 0; i < N; i++)
    {
        cin >> number;

        doors.push_back(number);
    }

    long long brokenDoors = 0, i = 0;

    while (!keys.empty() && i < N)
    {
        if (keys.count(doors[i]))
        {
            bool isThere = false;
            auto it = keys.find(doors[i]);
            for (int j = 0; j < it->second.size(); j++)
            {
                if (it->second[j] <= i)
                {
                    it->second.erase(it->second.begin() + j);
                    isThere = true;
                    break;
                }
            }    
            if (isThere == false)
            {
                brokenDoors++;
            }
        }
        else
        {
            brokenDoors++;
        }     
        i++;
    }

    printf("%lld", brokenDoors);

    return 0;
}