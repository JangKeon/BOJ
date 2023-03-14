// https://school.programmers.co.kr/learn/courses/30/lessons/154540

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
char map[101][101];
int visited[101][101];
int food = 0;

void dfs(int x, int y) {
    visited[x][y] = 1;
    food += map[x][y] - '0';
    for (int i = 0; i < 4; i++) {
        int ax = x + dx[i];
        int ay = y + dy[i];
        if (map[ax][ay] == 'X' || visited[ax][ay]) {
            continue;
        }
        if (ax < 0 || ax > N - 1 || ay < 0 || ay > M - 1) {
            continue;
        }
        dfs(ax, ay);
    }
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    N = maps.size();
    M = maps[0].size();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            map[i][j] = maps[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] != 'X' && !visited[i][j]) {
                dfs(i, j);
                answer.push_back(food);
                food = 0;
            }
        }
    }
    if (answer.empty())  answer.push_back(-1);
    else    sort(answer.begin(), answer.end());
    return answer;
}