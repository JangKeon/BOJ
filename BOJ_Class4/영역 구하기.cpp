#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int map[101][101];

struct rectangle {
	int x1, y1, x2, y2;
};

vector <rectangle> rec;

int main(void) {
	int N, M, K;
	cin >> M >> N >> K;
	int x, y, x2, y2;
	for (int i = 0; i < K; i++) {
		cin >> x >> y >> x2 >> y2;
		rec.push_back({ x,y,x2,y2 });
	}

	for (int u = 0; u < K; u++) {
		for (int i = rec[u].x1; i < rec[u].x2; i++) {
			for (int j = rec[u].y1; j < rec[u].y2; j++) {
				map[i][j] = 1;
			}
		}
	}

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
}
