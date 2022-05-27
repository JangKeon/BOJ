#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int map[101][101];
int visited[101][101];
int result[101][101];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int N, M;

void dfs(int x, int y) {
	visited[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int ax = x + dx[i];
		int ay = y + dy[i];

		if (ax < 1 || ax > N || ay < 1 || ay > M) {
			continue;
		}

		if (!visited[ax][ay] && map[ax][ay]) {
			result[ax][ay] = min(result[ax][ay], result[x][y] + 1);
			cout << ax << ' ' << ay <<  "Load!" << result[ax][ay] << '\n';
			dfs(ax, ay);
		}
	}

}

int main(void) {
	cin >> N >> M; 
	memset(result, 999999, sizeof(result)); 
	result[1][1] = 1;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf_s("%1d", &map[i][j]);
		}
	}
	dfs(1, 1);
	cout << result[N][M];
}