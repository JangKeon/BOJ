#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int map[51][51];
int visited[51][51];
int T, N, M, K;

void dfs(int x, int y) {
	visited[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int ax = x + dx[i];
		int ay = y + dy[i];

		if (ax < 0 || ax > M - 1 || ay < 0 || ay > N - 1) {
			continue;
		}

		if (visited[ax][ay] || !map[ax][ay]) {
			continue;
		}

		dfs(ax, ay);
	}
}

int main(void) {
	int x, y;
	cin >> T;
	for (int u = 0; u < T; u++) {
		cin >> M >> N >> K;	
		int result = 0;
		for (int i = 0; i < K; i++) {
			cin >> x >> y;
			map[x][y] = 1;
		}

		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				if (!visited[i][j] && map[i][j]) {
					dfs(i, j);
					result++;
				}
			}
		}
		cout << result << '\n';
		memset(map, 0, sizeof(map));
		memset(visited, 0, sizeof(visited));
	}
}