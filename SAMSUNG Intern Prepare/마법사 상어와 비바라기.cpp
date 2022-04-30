#include <iostream>
#include <queue>
#include <deque>
#include <string.h>
using namespace std;

int dx[8] = { 0, -1, -1, -1, 0, 1, 1, 1 };
int dy[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int map[50][50];
int visit[50][50];
int N, M;

struct m {
	int move;
	int distance;
};

struct cloud_location {
	int x;
	int y;
};

deque <cloud_location> cloud;
queue <m> rotation;

void copy_water(int x, int y) {
	int plus = 0;
	for (int i = 0; i < 4; i++) {
		int ax = x + dx[i + i + 1];
		int ay = y + dy[i + i + 1];
		if (ax < 0 || ax >= N || ay < 0 || ay >= N) {
			continue;
		}

		if (map[ax][ay]) {
			plus++;
		}
	}
	map[x][y] += plus;
}

void move_cloud(int dir, int dis) {

	for (int i = 0; i < cloud.size(); i++) {
		int nx = cloud[0].x;
		int ny = cloud[0].y;
		for (int j = 0; j < dis; j++) {
			nx += dx[dir - 1];
			ny += dy[dir - 1];
		}
		while (nx < 0 || nx > N - 1 || ny < 0 || ny > N - 1) {
			if (nx < 0) {
				nx += N;
			}
			if (nx > N - 1) {
				nx = nx - N;
			}
			if (ny < 0) {
				ny += N;
			}
			if (ny > N - 1) {
				ny = ny - N;
			}
		}
		cloud.push_back({ nx, ny });
		visit[nx][ny] = 1;
		cloud.pop_front();
	}
}

int main(void) {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	int m, d;
	for (int i = 0; i < M; i++) {
		cin >> m >> d;
		rotation.push({ m,d });
	}

	cloud.push_back({ N - 1, 0 });
	cloud.push_back({ N - 1, 1 });
	cloud.push_back({ N - 2, 0 });
	cloud.push_back({ N - 2, 1 });

	while (!rotation.empty()) {
		int rotate_move = rotation.front().move;
		int rotate_distance = rotation.front().distance;
		move_cloud(rotate_move, rotate_distance);

		for (int i = 0; i < cloud.size(); i++) {
			map[cloud[i].x][cloud[i].y]++;
		}

		for (int i = 0; i < cloud.size(); i++) {
			copy_water(cloud[i].x, cloud[i].y);
		}

		cloud.clear();
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] >= 2 && !visit[i][j]) {
					cloud.push_back({ i, j });
					map[i][j] -= 2;
				}
			}
		}
		memset(visit, 0, sizeof(visit));
		rotation.pop();
	}

	int total = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			total += map[i][j];
		}
	}
	cout << total;
}