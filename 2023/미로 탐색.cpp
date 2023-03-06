#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

int map[101][101];
int dp[101][101];
int visited[101][101];
int N, M;

struct point {
	int x;
	int y;
};
queue <point> que;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void bfs() {
	while (!que.empty()) {
		int x = que.front().x;
		int y = que.front().y;
		visited[x][y] = 1; // 있든 없든 상관 X. 어차피 초기 지점만 체크가 안 되는 거기 때문에.
		que.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 1 || nx > N || ny < 1 || ny > M || visited[nx][ny]) {
				continue;
			}
			if (!map[nx][ny]) {
				continue;
			}
			dp[nx][ny] = dp[x][y] + 1;
			visited[nx][ny] = 1; // 여기 visit 처리가 없으면 메모리 초과가 난다..!
			que.push({ nx, ny });
		}
	}
}

int main(void) {
	dp[1][1] = 1;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	que.push({ 1,1 });
	bfs();
	cout << dp[N][M];
}