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

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int N, M, R, K;
char map[100][100];
int visited[100][100];
deque <point> sword;
struct point dest;
queue <point> que;
int point_x = 0, point_y = 0, result = 0;

int Min(deque <point> a) {
	int Min = 9999;
	for (int i = 0; i < a.size(); i++) {
		if (visited[a[i].x][a[i].y] < Min) {
			Min = visited[a[i].x][a[i].y];
			point_x = a[i].x;	point_y = a[i].y;
		}
	}
	cout << "X : " << point_x << "Y : " << point_y << '\n';
	for (int i = 0; i < a.size(); i++) {
		if (visited[a[i].x][a[i].y] == Min) {
			sword.pop_front();
			sword.push_back({ a[i].x, a[i].y });
		}
		else {
			sword.pop_front();
		}
	}
	return Min;
}

void bfs_nosword() {
	int nx, ny;
	while (!que.empty()) {
		while (!que.empty()) {
			int x = que.front().x;
			int y = que.front().y;
			visited[x][y]++;
			que.pop();
			for (int i = 0; i < 4; i++) {
				nx = x + dx[i];
				ny = y + dy[i];
				if (nx < 0 || nx >= N || ny < 0 || ny >= M) {
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
}

int main(void) {
	int T;
	cin >> T;
	for (int u = 0; u < T; u++) {
		cin >> N >> M >> R >> K;
		result = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> map[i][j];
				if (map[i][j] == 'A' || map[i][j] == 'B' || map[i][j] == 'C') {
					sword.push_back({ i,j });
				}
				if (map[i][j] == 'S') {
					dest.x = i; dest.y = j;
				}
			}
		}

		que.push({ R, K });
		bfs_nosword();
		result += Min(sword);
		memset(visited, 0, sizeof(visited));
		que.push({ point_x, point_y });
		bfs_nosword();
		result += Min(sword);
		memset(visited, 0, sizeof(visited));
		que.push({ point_x, point_y });
		bfs_nosword();
		result += Min(sword);
		cout << result;
	}
}