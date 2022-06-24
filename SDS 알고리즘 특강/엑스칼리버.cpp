#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

struct point {
	int x;
	int y;
};

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int N, M, R, K;
char map[101][101];
int visited[101][101];
vector <point> sword;
struct point dest;
queue <point> que;
int cost[9];
int result[6];

void bfs() {
	int nx, ny;
	while (!que.empty()) {
		int x = que.front().x;
		int y = que.front().y;
		que.pop();
		for (int i = 0; i < 4; i++) {
			nx = x + dx[i];
			ny = y + dy[i];
			if (nx < 1 || nx > N || ny < 1 || ny > M) {
				continue;
			}
			if (map[nx][ny] == 'X' || visited[nx][ny]) {
				continue;
			}
			visited[nx][ny] = visited[x][y] + 1;
			que.push({ nx, ny });
		}
	}
}

int main(void) {
	int T;
	cin >> T;
	for (int i = 0; i < 3; i++) {
		sword.push_back({ 0, 0 });
	}
	for (int u = 0; u < T; u++) {
		cin >> N >> M >> R >> K;
		memset(visited, 0, sizeof(visited));
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				cin >> map[i][j];
				if (map[i][j] == 'A') {
					sword[0].x = i; sword[0].y = j;
				}
				if (map[i][j] == 'B') {
					sword[1].x = i; sword[1].y = j;
				}
				if (map[i][j] == 'C') {
					sword[2].x = i; sword[2].y = j;
				}
				if (map[i][j] == 'S') {
					dest.x = i; dest.y = j;
				}
			}
		}

		que.push({ R , K });
		visited[R][K] = 1;
		bfs();
		for (int i = 0; i < 3; i++) {
			cost[i] = visited[sword[i].x][sword[i].y] - 1;
		}

		memset(visited, 0, sizeof(visited));
		que.push({ sword[0].x, sword[0].y });
		visited[sword[0].x][sword[0].y] = 1;
		bfs();
		for (int i = 3; i < 5; i++) {
			cost[i] = visited[sword[i - 2].x][sword[i - 2].y] - 1;
		}

		memset(visited, 0, sizeof(visited));
		que.push({ sword[1].x, sword[1].y });
		visited[sword[1].x][sword[1].y] = 1;
		bfs();
		cost[5] = visited[sword[2].x][sword[2].y] - 1;

		for (int i = 6; i < 9; i++) {
			cost[i] = abs(dest.x - sword[i - 6].x) + abs(dest.y - sword[i - 6].y);
		}

		result[0] = cost[0] + cost[3] + cost[5] + cost[8];
		result[1] = cost[0] + cost[4] + cost[5] + cost[7];
		result[2] = cost[1] + cost[3] + cost[4] + cost[8];
		result[3] = cost[1] + cost[4] + cost[5] + cost[6];
		result[4] = cost[2] + cost[3] + cost[4] + cost[7];
		result[5] = cost[2] + cost[3] + cost[5] + cost[6];

		int Min = 999999;
		for (int i = 0; i < 6; i++) {
			if (Min > result[i]) {
				Min = result[i];
			}
		}
		cout << "#" << u + 1 << ' ' << Min << '\n';
	}
}