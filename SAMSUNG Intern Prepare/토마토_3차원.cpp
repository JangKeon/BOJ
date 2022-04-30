#include <iostream>
#include <queue>
using namespace std;

int map[101][101][101];
int dx[6] = { 1, 0, 0, -1, 0, 0 };
int dy[6] = { 0, 1, -1, 0, 0, 0 };
int dz[6] = { 0, 0, 0, 0, 1, -1 };
int M, N, H, res = -9999;

struct tomato {
	int x;
	int y;
	int z;
};

queue <tomato> que;

void bfs() {
	int nx, ny, nz;
	while (!que.empty()) {
		int x = que.front().x;
		int y = que.front().y;
		int z = que.front().z;
		que.pop();
		for (int i = 0; i < 6; i++) {
			nx = x + dx[i];
			ny = y + dy[i];
			nz = z + dz[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M || nz < 0 || nz >= H) {
				continue;
			}

			if (map[nx][ny][nz]) {
				continue;
			}

			map[nx][ny][nz] = map[x][y][z] + 1;
			que.push({ nx, ny, nz });

		}
	}
}

int main(void) {
	cin >> M >> N >> H;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				cin >> map[j][k][i];
				if (map[j][k][i] == 1) {
					que.push({j, k, i});	
				}
			}
		}
	}
	bfs();
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				if (map[j][k][i] == 0) {
					cout << "-1\n";
					return 0;
				}

				if (res < map[j][k][i]) {
					res = map[j][k][i];
				}
			}
		}
	}
	cout << res - 1;
}