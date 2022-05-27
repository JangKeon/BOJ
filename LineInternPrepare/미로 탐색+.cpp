#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int map[101][101];
int visited[101][101];
int result[101][101];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int N, M;

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

			if (!visited[nx][ny] && map[nx][ny]) {
				que.push({ nx, ny });
				visited[nx][ny] = 1;
				result[nx][ny] = result[ax][ay] + 1;
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
	result[1][1] = 1;
	que.push({ 1, 1 });
	bfs();
	cout << result[N][M];
}