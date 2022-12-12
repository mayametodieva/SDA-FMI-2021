#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

void Merge(vector<int>& vec, int start, int mid, int end) {
    vector<int> temp;

    int i, j;
    i = start;
    j = mid + 1;

    while (i <= mid && j <= end)
    {
        if (vec[i] > vec[j]) {
            temp.push_back(vec[i]);
            ++i;
        }
        else {
            temp.push_back(vec[j]);
            ++j;
        }
    }

    while (i <= mid) {
        temp.push_back(vec[i]);
        ++i;
    }

    while (j <= end) {
        temp.push_back(vec[j]);
        ++j;
    }

    for (int i = start; i <= end; ++i)
        vec[i] = temp[i - start];

}

void MergeSort(vector<int>& vec, int start, int end) {
    if (start < end) {
        int mid = (start + end) / 2;
        MergeSort(vec, start, mid);
        MergeSort(vec, mid + 1, end);
        Merge(vec, start, mid, end);
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;

    cin >> N;

    vector<int> vals(N);

    for (int i = 0; i < N; i++)
    {
        cin >> vals[i];
    }

    MergeSort(vals, 0, N - 1);

    for (int i = 0; i < N; i++)
    {
        printf("%d ", vals[i]);
    }
    return 0;
}
