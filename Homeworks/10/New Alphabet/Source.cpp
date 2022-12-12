#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <stack>
using namespace std;

unordered_map<char, vector<char>> adjacent;
bool visited[123];
stack<char> alphabet;

void dfs(char letter) {
    visited[letter] = 1;
    for (auto it : adjacent[letter]) {
        if (!visited[it]) {
            dfs(it);
        }
    }
    alphabet.push(letter);
}

int main() {

    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;

    cin >> N;

    vector<string> words(N);

    for (int i = 0; i < N; i++)
    {
        cin >> words[i];
        int j = 0;
        while (j < words[i].size()) {
            if (adjacent.count(words[i][j]) == 0)
            {
                adjacent[words[i][j]] = vector<char>();
            }
            j++;
        }
    }

    for (int i = 0; i < N - 1; i++)
    {
        int j = 0;
        while (j < min(words[i].size(), words[i + 1].size()))
        {
            if (N == 1 || N == 2 && words[i][j] == words[i + 1][j])
            {
                adjacent.clear();
            }
            if (words[i][j] != words[i + 1][j])
            {
                adjacent[words[i][j]].push_back(words[i + 1][j]);
                break;
            }
            j++;
        }
    }

    for (auto it : adjacent) {
        if (!visited[it.first])
        {
            dfs(it.first);
        }
    }

    while (!alphabet.empty())
    {
        printf("%c ", alphabet.top());
        alphabet.pop();
    }

    return 0;
}
