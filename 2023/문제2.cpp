#include <iostream>
#include <queue>
using namespace std;

struct point {
	int x;
	int y;
};

int N;
char map[1001][1001];
int cost[1001][1001];
int visited[1001][1001];
point start, wayout, holeA_in, holeA_out, holeB_in, holeB_out;
queue <point> que;
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
			if (nx < 0 || nx > N - 1 || ny < 0 || ny > N - 1) {
				continue;
			}
			if (map[nx][ny] == '1' || visited[nx][ny]) {
				continue;
			}
			if (nx == holeA_in.x && ny == holeA_in.y) {
				cost[holeA_out.x][holeA_out.y] = cost[x][y] + 2;
				visited[holeA_in.x][holeA_in.y] = 1;
				visited[holeA_out.x][holeA_out.y] = 1;
				que.push({ holeA_out.x, holeA_out.y });
				continue;
			}
			if (nx == holeB_in.x && ny == holeB_in.y) {
				cost[holeB_out.x][holeB_out.y] = cost[x][y] + 2;
				visited[holeB_in.x][holeB_in.y] = 1;
				visited[holeB_out.x][holeB_out.y] = 1;
				que.push({ holeB_out.x, holeB_out.y });
				continue;
			}
			cost[nx][ny] = cost[x][y] + 1;
			visited[nx][ny] = 1;
			que.push({ nx, ny });
		}
	}
}

int main(void) {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'S') {
				start.x = i; start.y = j;
				que.push({ i, j });
				cost[i][j] = 1;
				visited[i][j] = 1;
			}
			if (map[i][j] == 'E') {
				wayout.x = i; wayout.y = j;
			}
			if (map[i][j] == 'A') {
				holeA_in.x = i; holeA_in.y = j;
			}
			if (map[i][j] == 'B') {
				holeB_in.x = i; holeB_in.y = j;
			}
			if (map[i][j] == 'a') {
				holeA_out.x = i; holeA_out.y = j;
			}
			if (map[i][j] == 'b') {
				holeB_out.x = i; holeB_out.y = j;
			}
		}
	}
	bfs();
	if (cost[wayout.x][wayout.y] == 0)	cout << -1;
	else	cout << cost[wayout.x][wayout.y];
}