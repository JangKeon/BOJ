#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef struct tomato {
	int x;
	int y;
};

int map[1002][1002];
queue <tomato> que;
int N, M, num, res = 0;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

void bfs() {
	int nx, ny;
	while (!que.empty()) {
		int x = que.front().x;
		int y = que.front().y;
		que.pop();
		for (int i = 0; i < 4; i++) {
			nx = x + dx[i];
			ny = y + dy[i];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M) {
				continue;
			}
			if (map[nx][ny]) {
				continue;
			}
			map[nx][ny] = map[x][y] + 1;
			que.push({ nx, ny });
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) {
				que.push({ i, j });
			}
		}
	}
	bfs();
	int res = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0) {
				cout << "-1\n";
				return 0;
			}
			if (res < map[i][j]) {
				res = map[i][j];
			}
		}
	}
	cout << res - 1;
}
