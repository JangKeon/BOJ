#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

int map[101][101];

int main(void) {
	fill(&map[0][0], &map[100][101], 987654321);

	int	n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) {
				map[i][j] = 0;
			}
		}
	}

	int start, end, weight;
	for (int i = 0; i < m; i++) {
		cin >> start >> end >> weight;
		map[start][end] = min(map[start][end], weight);
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (map[i][k] + map[k][j] < map[i][j]) {
					map[i][j] = map[i][k] + map[k][j];
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (map[i][j] == 987654321) {
				cout << 0 << ' ';
			}
			else cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
}