#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct point {
	int x;
	int y;
};

queue <point> que;
char map[101][101];
int visited[101][101];

int dx[4] = { 1, 0, 0, -1 };
int dy[4] = { 0, 1, -1, 0 };
int N, normal = 0, strange = 0;	

void bfs_right() {
	while (!que.empty()) {
		int ax = que.front().x;
		int ay = que.front().y;
		que.pop();
		if (map[ax][ay] == 'R') {
			for (int i = 0; i < 4; i++) {
				int nx = ax + dx[i];
				int ny = ay + dy[i];
				if (nx < 1 || nx > N || ny < 1 || ny > N) {
					continue;
				}
				if (!visited[nx][ny] && map[nx][ny] == 'R') {
					que.push({ nx, ny });
					visited[nx][ny] = 1;
				}
			}
		}

	}

}

void bfs_wrong() {

}

int main(void) {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}
	que.push({ 1, 1 });
	visited[1][1] = 1;
}