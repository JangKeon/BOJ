#include <iostream>
using namespace std;

int main(void) {
	int arr[8][8] = {
		{1, 0, 1, 0, 1, 0, 1, 0},
		{0, 1, 0, 1, 0, 1, 0, 1},
		{1, 0, 1, 0, 1, 0, 1, 0},
		{0, 1, 0, 1, 0, 1, 0, 1},
		{1, 0, 1, 0, 1, 0, 1, 0},
		{0, 1, 0, 1, 0, 1, 0, 1},
		{1, 0, 1, 0, 1, 0, 1, 0},
		{0, 1, 0, 1, 0, 1, 0, 1},
	};

	char board[8][8];
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cin >> board[i][j];
		}
	}

	int res = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (arr[i][j] && board[i][j] == 'F') {
				res++;
			}
		}
	}
	cout << res;
}