#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int map[2188][2188];
bool visit[2188][2188];

int dx[4] = { 1,0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int result[3] = { 0, 0, 0 };
int N;

int dfs(int x, int y ) {
	visit[x][y] = true;
	int number = map[x][y];
	for (int i = 0; i < 4; i++) {
		int ax = x + dx[i]; 
		int ay = y + dy[i];
		if (ax < 0 || ax > N - 1|| ay < 0 || ay > N - 1) {
			continue;
		}
		if (visit[ax][ay]) {
			continue;
		}
		if (map[ax][ay] == number) {
			dfs(ax, ay);
		}	
	}
	return number;
}

int main(void) {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			result[dfs(i, j)] ++;
		}
	}

	for (int i = 0; i < 3; i++) {
		cout << result[i] << '\n';
	}
}