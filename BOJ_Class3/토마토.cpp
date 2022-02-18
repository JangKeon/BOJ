#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef struct tomato {
	int x;
	int y;
};
int map[1002][1002];
queue <tomato> que;
bool check[1002][1002] = { false, };
int N, M, num, res = 0;

void bfs(int x, int y) {
	que.push(map[x][y]);
	check[x][y] = true;
	while (!que.empty()) {
		int a = que.front();
		que.pop();
		if (a == 1) {
			if (!check[x - 1][y]) {
				if (map[x - 1][y] == 0) {
					map[x - 1][y] = 1;
					que.push(map[x - 1][y]);
					check[x - 1][y] = true;
				}
			}
			if (!check[x + 1][y]) {
				if (map[x + 1][y] == 0) {
					map[x + 1][y] = 1;
					que.push(map[x + 1][y]);
					check[x + 1][y] = true;
				}
			}

			if (!check[x][y + 1]) {
				if (map[x][y + 1] == 0) {
					map[x][y + 1] = 1;
					que.push(map[x][y + 1]);
					check[x][y + 1] = true;
				}
			}

			if (!check[x][y - 1]) {
				if (map[x][y - 1] == 0) {
					map[x][y - 1] = 1;
					que.push(map[x][y - 1]);
					check[x][y - 1] = true;
				}
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> M >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (!check[i][j]) {
				bfs(i, j);
			}
		}
	}
	cout << res;
}
