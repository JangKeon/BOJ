#include <iostream>
using namespace std;

int map[1025][1025];
int sum_row[1025][1025];

int main(void) {
	int N, M;
	ios::sync_with_stdio();
	cin.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			sum_row[i][j] = map[i][j] + sum_row[i - 1][j];
		}
	}

	int x1, y1, x2, y2;
	for (int i = 0; i < M; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		int result = 0;
		for (int i = y1; i <= y2; i++) {
			result += (sum_row[x2][i] - sum_row[x1-1][i]);
		}
		cout << result << '\n';
	}
}