
#include <iostream>
#include <set>
#include <iterator>
#include <cmath>

using namespace std;

/*
5
7
3
5
5
42
*/

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    int num;

    set<int> numbers;
    numbers.insert(0);

    int result = pow(10, 9);

    for (int i = 0; i < N; i++)
    {
        cin >> num;

        auto it = numbers.insert(num);

        if (it.second == false)
        {

        }

        printf("%d\n", result);
        //0 1 4 8 11 5 5  

        //1 2 3 4 5 6

        
    }
}
