#include <iostream>
#include <queue>
using namespace std;

int map[1001][1001];
int cost[1001][1001];
int visited[1001][1001];
int crash = 0;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int N, M;
bool check = false;

struct point {
	int x;
	int y;
};

queue <point> que;

void bfs() {
	while (!que.empty()) {
		int ax = que.front().x;
		int ay = que.front().y;
		que.pop();
		for (int i = 0; i < 4; i++) {
			int nx = ax + dx[i];
			int ny = ay + dy[i];

			if (nx < 1 || nx > N || ny < 1 || ny > M) {
				continue;
			}

			if (nx == N && ny == M) {
				cout << cost[ax][ay] + 1;
				check = true;
				return;
			}

			if (!visited[nx][ny] && map[nx][ny] == 0) {
				que.push({ nx, ny });
				visited[nx][ny] = 1;
				cost[nx][ny] = cost[ax][ay] + 1;
			}

			if (!visited[nx][ny] && crash == 0 && map[nx][ny] == 1) {
				for (int k = 0; k < 4; k++) {
					int zx = nx + dx[i];
					int zy = ny + dy[i];

					if (zx < 1 || zx > N || zy < 1 || zy > M) {
						continue;
					}

					if (!visited[zx][zy] && map[zx][zy] == 0) {
						que.push({ zx, zy });
						que.push({ nx, ny });
						visited[zx][zy] = 1;
						visited[nx][ny] = 1;
						cost[nx][ny] = cost[ax][ay] + 1;
						cost[zx][zy] = cost[ax][ay] + 2;
						crash = 1;
					}
				}
			}
		}
	}


}

int main(void) {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf_s("%1d", &map[i][j]);
		}
	}
	que.push({ 1,1 });
	cost[1][1] = 1;
	visited[1][1] = 1;
	bfs();
	if (!check) {
		cout << "-1\n";
	}
}