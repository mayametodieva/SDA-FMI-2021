#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;

const int N = 1000;
bool matrix[N][N];

const int MOVE_SIZE = 4;
int moveX[MOVE_SIZE] = { 1,-1,0,0 };
int moveY[MOVE_SIZE] = { 0,0,1,-1 };

bool valid(int x, int y, int n, int m) {
    return x > 0 && y > 0 && x <= n && y <= m && !matrix[x][y];
}

int findNumberOfUnhealthyStudents(queue<pair<int, int>> traversed, int t, int n, int m, int sum) {
    queue<pair<int, int>> temp;

    for (int i = 0; i < t; i++)
    {
        while (!traversed.empty())
        {
            int currX = traversed.front().first, currY = traversed.front().second;
            traversed.pop();

            for (int j = 0; j < MOVE_SIZE; j++)
            {
                if (valid(currX + moveX[j], currY + moveY[j], n, m))
                {
                    sum++;
                    temp.push({ currX + moveX[j], currY + moveY[j] });
                    matrix[currX + moveX[j]][currY + moveY[j]] = 1;
                }
            }
        }

        while (!temp.empty())
        {
            traversed.push(temp.front());
            temp.pop();
        }
    }

    return sum;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, T, K;

    cin >> n >> m >> T >> K;

    int sum = K;

    queue<pair<int, int>> traversed;

    for (int i = 0; i < K; i++)
    {
        int first, second;

        cin >> first >> second;

        matrix[first][second] = 1;

        traversed.push({ first, second });
    }

    sum = findNumberOfUnhealthyStudents(traversed, T, n, m, sum);

    printf("%d", m * n - sum);

    return 0;
}