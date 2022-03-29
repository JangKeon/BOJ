#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool visit[27][27];
bool building[27][27];
int cnt;

void dfs(int x, int y) {
	visit[x][y] = true;
	cnt++;
	int dx[4] = { 1, -1, 0, 0 };
	int dy[4] = { 0, 0, 1, -1 };
	for (int i = 0; i < 4; i++) {
		int ax = x + dx[i];
		int ay = y + dy[i];
		if (!building[ax][ay] || visit[ax][ay]) {
			continue;
		}
		dfs(ax, ay);
	}
}

int main(void) {
	int M, bit, res = 0;
	vector <int> vec;
	cin >> M;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &bit);
			if (bit == 1) {
				building[i + 1][j + 1] = true;
			}
		}
	}

	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= M; j++) {
			if (building[i][j] && !visit[i][j]) {
				cnt = 0;
				dfs(i, j);
				res++;
				vec.push_back(cnt);
			}
		}
	}

	sort(vec.begin(), vec.end());
	cout << res << '\n';
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << '\n';
	}
}