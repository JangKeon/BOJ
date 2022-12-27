#include <stdio.h>
#include <iostream>
using namespace std;

int map[51][51];
int visited[51][51];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int N, M, K;

void dfs(int x, int y) {
	visited[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int ax = x + dx[i];
		int ay = y + dy[i];
		if (ax < 0 || ax > M || ay < 0 || ay > N) {
			continue;
		}
		if (!map[ax][ay] || visited[ax][ay]) {
			continue;
		}
		dfs(ax, ay);
	}
}

int main(void) {
	int T;
	cin >> T;
	for (int u = 0; u < T; u++) {
		cin >> M >> N >> K;
		int a, b, answer = 0;
		for (int i = 0; i < K; i++) {
			cin >> a >> b;
			map[a][b] = 1;
		}

		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] && !visited[i][j]) {
					dfs(i, j);
					answer++;
				}
			}
		}
		cout << answer << '\n';
		memset(map, 0, sizeof(map));
		memset(visited, 0, sizeof(visited));
	}

}