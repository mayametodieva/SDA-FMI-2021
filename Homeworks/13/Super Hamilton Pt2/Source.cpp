
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int rows, cols, to_visit, result = 0, start_r = 0, start_c = 0, end_r = 0, end_c = 0;
char maze[25][25];
bool visited[25][25];

int arr1[] = { 0,1,0,-1 };
int arr2[] = { -1,0,1,0 };
int n;

bool is_valid(int i, int j)
{
    return i >= 0 && j >= 0 && i < rows&& j < cols && maze[i][j] != 'x' && !visited[i][j];
}

bool isEnd(pair<int, int> idx, int count) {
    return idx.first == end_r && idx.second == end_c && to_visit == count;
}

void backtrack(int current_x, int current_y, int visited_count)
{
    if (isEnd({current_x, current_y}, visited_count))
    {
        result++;

        return;
    }
    
    visited[current_x][current_y] = true;
    for (int i = 0; i < 4; i++)
    {
        int neighbor_x = current_x + arr1[i];
        int neighbor_y = current_y + arr2[i];

        if (is_valid(neighbor_x, neighbor_y))
        {
            backtrack(neighbor_x, neighbor_y, visited_count + 1);
        }
    }

    visited[current_x][current_y] = false;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> rows >> cols;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> maze[i][j];

            if (maze[i][j] == 's')
            {
                start_r = i;
                start_c = j;
            }
            else if (maze[i][j] == 'e')
            {
                end_r = i;
                end_c = j;

                to_visit++;
            }
            else if (maze[i][j] == '-')
                to_visit++;
        }
    }

    visited[start_r][start_c] = true;

    backtrack(start_r, start_c, 0);

    cout << result << '\n';

    return 0;
}
