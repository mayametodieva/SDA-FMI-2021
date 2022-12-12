#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

pair<int, int> findMinOfEls(vector<long long>& vec, long long start, long long end) {
    long long min = vec[start];
    long long minIdx = start;
    for (long long i = start + 1; i <= end; i++)
    {
        if (min > vec[i])
        {
            min = vec[i];
            minIdx = i;
        }
    }
    return { min, minIdx };
}
//
//long long findMinIdxOfEls(vector<long long>& vec, long long start, long long end) {
//    long long i = 0;
//    long long min = vec[start];
//    for (i = start + 1; i <= end; i++)
//    {
//        if (min > vec[i])
//        {
//            min = vec[i];
//            return i;
//        }
//    }
//
//}

long long findSumOfMinElements(vector<long long>& vec, long long d, long long N) {
    //long long minIdx = 0;
    //
    //long long min = vec[0];

    //for (int j = 0; j <= d; j++)
    //{
    //    if (min > vec[j])
    //    {
    //        min = vec[j];
    //        minIdx = j;
    //    }
    //}
    //long long sum = min;

    //for (long long i = d; i < N; i++)
    //{

    //    if (minIdx >= i - d + 1 && minIdx <= i)
    //    {
    //        sum += min;
    //    }
    //    else
    //    {
    //        long long newMin = vec[i - d + 1];
    //        for (long long j = i - d + 2; j <= i; j++)
    //        {
    //            if (newMin > vec[j])
    //            {
    //                newMin = vec[j];
    //                minIdx = j;
    //            }
    //        }
    //        min = newMin;
    //        sum += min;
    //    }        
    //}
    //return sum;


    //long long minIdx = -1, min = 0, sum = 0;

    //for (long long i = 0; i < N - d + 1; i++)
    //{
    //    cout << min << " ";
    //    if (minIdx >= i && minIdx <= i + d)
    //    {
    //        sum += min;
    //    }
    //    else
    //    {
    //        long long newMIn = vec[i];
    //        for (long long j = i; j < i + d; j++)
    //        {
    //            if (newMIn >= vec[j])
    //            {
    //                newMIn = vec[j];
    //                minIdx = j;

    //            }              
    //        }
    //        min = newMIn;
    //        sum += min;
    //    }
    //}
    //return sum;

    pair<int, int> minVals = findMinOfEls(vec, 0, d);

    long long minIdx = minVals.second;

    long long min = minVals.first;

    long long sum = min;


    for (long long i = d; i < N; i++)
    {
        if (minIdx >= i - d + 1 && minIdx <= i && min < vec[i])
        {
            sum += min;
        }
        else
        {
            pair<int, int> newMin = findMinOfEls(vec, i - d + 1, i);
            min = newMin.first;
            minIdx = newMin.second;
            sum += min;
        }
        
    }
    return sum;
}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, d;

    cin >> N >> d;

    vector<long long> numbers(N);

    for (long long i = 0; i < N; i++)
    {
        cin >> numbers[i];
    }

    printf("%lld ", findSumOfMinElements(numbers, d, N));
    return 0;
}