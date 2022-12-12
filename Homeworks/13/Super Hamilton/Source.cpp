#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 25;
int rows = 0, columns = 0, countOfNodesForVisiting = 0, numberOfWays = 0;
pair<int, int> startPoint, endPoint;
bool visited[N][N]{ 0 };
char matrix[N][N];

const int MOVE_SIZE = 4;
int moveX[MOVE_SIZE] = { -1,1,0,0 };
int moveY[MOVE_SIZE] = { 0,0,1,-1 };

void check(int i, int j) {
    if (matrix[i][j] == 's')
    {
        startPoint = { i,j };
    }
    else if (matrix[i][j] == '-')
    {
        countOfNodesForVisiting++;
    }
    else if (matrix[i][j] == 'e') {
        endPoint = { i,j };
        countOfNodesForVisiting++;
    }
}

bool isValid(int i, int j) {
    return i >= 0 && j >= 0 && i < rows && j < columns&& matrix[i][j] != 'x' && !visited[i][j];
}

bool isEnd(pair<int, int> idx, int count) {
    return idx == endPoint && countOfNodesForVisiting == count;
}

void hamilton(pair<int, int> position, int count) {

    if (isEnd(position, count))
    {
        numberOfWays++;
        return;
    }

    int curr_x = position.first, curr_y = position.second;
    
    visited[curr_x][curr_y] = 1;

    for (int i = 0; i < MOVE_SIZE; i++)
    {
        if (isValid(curr_x + moveX[i], curr_y + moveY[i]))
        {
            hamilton({ curr_x + moveX[i], curr_y + moveY[i] }, count + 1);
        }
    }

    visited[curr_x][curr_y] = 0;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> rows >> columns;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cin >> matrix[i][j];
            check(i, j);
        }
    }

    visited[startPoint.first][startPoint.second] = 1;

    hamilton(startPoint, 0);

    printf("%d", numberOfWays);

    return 0;
}
