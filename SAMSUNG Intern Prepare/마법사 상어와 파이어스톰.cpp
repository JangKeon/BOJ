#include <iostream>
using namespace std;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0 ,1, 0, -1 };

int N, L, Q;
int map[64][64];
int change_map[64][64];
int visit[64][64] = {0, };
int mass = 0;

void dfs(int x, int y) {
	visit[x][y] = 1;
	for (int k = 0; k < 4; k++) {
		int nx = map[x][y] + dx[k];
		int ny = map[x][y] + dy[k];

		if (nx < 0 || nx > pow(2, N) - 1 || ny <0 || ny > pow(2, N)) {
			continue;
		}

		if (!visit[nx][ny] && map[nx][ny]) {
			dfs(nx, ny);
		}
		mass++;
	}

}

void firestorm(int L) {

	for (int i = 0; i < pow(2, N); i++) {
		for (int j = 0; j < pow(2, N); j++) {
			
		}
	}

	for (int i = 0; i < pow(2, N); i++) {
		for (int j = 0; j < pow(2, N); j++) {
			
			int near_ice = 0;
			for (int k = 0; k < 4; k++) {
				int nx = map[i][j] + dx[k];
				int ny = map[i][j] + dy[k];
				
				if (nx < 0 || nx > pow(2, N) - 1 || ny <0 || ny > pow(2, N)) {
					continue;
				}
				
				if (map[nx][ny]) {
					near_ice++;
				}

				if (near_ice < 3) {
					if (map[i][j] > 0) {
						map[i][j] --;
					}
				}


			}
		}
	}
}

int main(void) {
	cin >> N >> Q;

	for (int i = 0; i < pow(2, N); i++) {
		for (int j = 0; j < pow(2, N); j++) {
			cin >> map[i][j];
		}
	}


	for (int i = 0; i < pow(2, N); i++) {
		for (int j = 0; j < pow(2, N); j++) {
			dfs(i, j);
		}
	}
}
