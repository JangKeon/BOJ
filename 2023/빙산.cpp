#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[4] = { 1, 0, -1 , 0 };
int dy[4] = { 0, 1, 0, -1 };
int map[301][301];

struct point {
	int x;
	int y;
};

void melting(int x, int y) {
	int melt = 0;
	for (int i = 0; i < 4; i++) {
		int ax = x + dx[i];
		int ay = y + dy[i];
		if (!map[ax][ay]) {
			melt++;
		}
	}
	map[x][y] -= melt;
	if (map[x][y] < 0) {
		map[x][y] = 0;
	}
}


int main(void) {
	int N, M;
	cin >> N >> M;
	queue <point> que;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j]) {
				que.push({ i, j });
			}
		}
	}
	int res = 0;
	while (1) {
		if (que.empty()) {
			cout << res;
			break;
		}
		int temp = que.size();
		for (int i = 0; i < temp; i++) {
			melting(que.front().x, que.front().y);
			if (!map[que.front().x][que.front().y]) {
				que.pop();
			}
			else {
				que.pop();
				que.push({ que.front().x, que.front().y });
			}
		}
		res++;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cout << map[i][j] << ' ';
			}
			cout << '\n';
		}
		cout << '\n';
	}

}