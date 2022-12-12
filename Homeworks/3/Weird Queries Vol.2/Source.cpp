#include <iostream>
#include<algorithm>
#include <vector>
using namespace std;
#pragma warning(disable:4996)

long long binarySearch(vector<long long> arr, long long difference) {
	long long N = arr.size();
	long long left = 0;
	long long right = N;
	long long mid = 0;

	if (difference <= arr[0])
	{
		return -1;
	}
	if (difference >= arr[N - 1])
	{
		return N - 1;
	}

	while (left <= right)
	{
		mid = (right + left) / 2;
		
		if (difference == arr[mid]) {

			return mid;
		}
		if (difference < arr[mid])
		{
			if (mid > 0 && difference > arr[mid - 1])
			{
				return mid;
			}
			right = mid;
		}
		else
		{
			if (mid < N - 1 && difference < arr[mid + 1])
			{
				return mid + 1;
			}
			left = mid + 1;
		}
	}	
	return mid;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, Q;

    cin >> N >> Q;

    vector<long> arr(N);
    for (long i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    vector<pair<long, long>> reqs(Q);

    for (long i = 0; i < Q; i++)
    {
        cin >> reqs[i].first >> reqs[i].second;
    }

    sort(arr.begin(), arr.end());

    vector<long> sums(N);

    sums[0] = arr[0];

    for (long i = 1; i < N; i++)
    {
        sums[i] = arr[i] + sums[i - 1];
    }

    for (long i = 0; i < Q; i++)
    {
        vector<long>::iterator up;
        up = upper_bound(arr.begin(), arr.end(), reqs[i].second);
        long idx_end = (up - arr.begin() - 1);

        long difference = sums[idx_end] - reqs[i].first;

        long idx_start = 0;

        if (reqs[i].first > sums[idx_end])
        {
            idx_end++;
        }
        else if (difference <= sums[0])
        {
            idx_start = -1;
        }
        else
        {
            vector<long>::iterator sec;
            sec = lower_bound(sums.begin(), sums.end(), difference);
            idx_start = (sec - sums.begin());
        }
        printf("%ld \n", (idx_end - idx_start));
    }
    return 0;
}