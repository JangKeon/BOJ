#include <queue>
#include <iostream>
using namespace std;

struct tomato {
	int x;
	int y;
};

queue <tomato> que;
int map[1001][1001];
int N, M, num;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void bfs() {
	int nx, ny;
	while (!que.empty()) {
		int x = que.front().x;
		int y = que.front().y;
		que.pop();
		for (int i = 0; i < 4; i++) {
			nx = x + dx[i];
			ny = y + dy[i];
			if (nx < 0 || nx > N - 1 || ny < 0 || ny > M - 1) {
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
	int res = 0;
	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> num;
			map[i][j] = num;
			if (map[i][j] == 1) {
				que.push({ i, j });
			}
		}
	}
	bfs();
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
	cout << res - 1 << '\n';
}