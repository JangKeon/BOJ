#include <iostream>
using namespace std;

int map[128][128] = { 0, }, paper[2];

void Cut(int x, int y, int N) {
	bool check = false;
	int cur = map[x][y];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (cur != map[x + i][y + j]) {
				check = true;
				break;
			}
		}
	}
	if (check) {
		Cut(x, y, N / 2);
		Cut(x, y + (N / 2), N / 2);
		Cut(x + (N / 2), y , N / 2);
		Cut(x + (N / 2), y + (N / 2), N / 2);
	}
	else {
		paper[cur] ++;
	}
}

int main(void) {
	int N, num;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> num;
			map[i][j] = num;
		}
	}
	Cut(0, 0, N);
	cout << paper[0] << ' ' << paper[1];
}