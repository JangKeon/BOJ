#include <iostream>
#include <string>
#include <vector>
using namespace std;

int map[20][20];
int visited[20][20];
int N, M;
int dir = 0, result = 0;
int current_x, current_y;

int clean(int x, int y) {
    int dx[4] = { 0, 1, 0, -1 };
    int dy[4] = { 1, 0, -1, 0 };

    visited[x][y] = 1;
    result++;
    current_x = dx[dir];
    current_y = dy[dir];

    int ax = x + current_x;
    int ay = y + current_y;

    if (visited[ax][ay]) {
        return result;
    }

    if (ax < 0 || ax > N - 1 || ay < 0 || ay > M - 1 || !map[ax][ay]) {
        dir++;
        result--;
        if (dir == 4)   dir = 0;
        clean(x, y);
    }
    else {
        clean(ax, ay);
    }

}

int solution(vector<string>& R) {
    N = R.size();
    M = R[0].size();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (R[i][j] == '.') {
                map[i][j] = 1;
            }
            else map[i][j] = 0;
        }
    }
    clean(0, 0);
    return result;
}



int main(void) {
    vector <string> a = { "...X..", "....XX", "..X..." };
    solution(a);
}


