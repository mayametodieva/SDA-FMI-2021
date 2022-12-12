#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;


void battle(stack<long long>& warriors, long long top, long long num) {
    while (abs(num) >= top) {
        
        if (abs(num) == top)
        {
            warriors.pop();
            break;
        }
        
        if (warriors.size() == 1)
        {
            if (warriors.top() >= 0)
            {
                warriors.pop();
            }
            warriors.push(num);
            break;
        }
        
        if (top < 0)
        {
            warriors.push(num);
            break;
        }
                
        warriors.pop();
        top = warriors.top();
    }
}

void reverseStack(stack<long long>& st) {
    stack<long long>st2;
    while (!st.empty()) {
        st2.push(st.top());
        st.pop();
    }
    st = st2;
}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long N;

    cin >> N;

    stack<long long> warriors;

    long long first;

    cin >> first;

    warriors.push(first);

    for (long long i = 0; i < N - 1; i++)
    {
        long long num;
        cin >> num;

        if (warriors.empty())
        {
            warriors.push(num);
        }
        else if (num < 0 && warriors.top() >= 0)
        {
            battle(warriors, warriors.top(), num);
        }
        else
        {
            warriors.push(num);
        }
    }

    reverseStack(warriors);

    while (!warriors.empty()) {
        printf("%lld ", warriors.top());
        warriors.pop();
    }

    return 0; 
}