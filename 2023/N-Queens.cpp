#include <iostream>
using namespace std;

int n, dist = 0;
int board[15];

void NQueens(int col) {
	if (col == n) {
		dist++;
	}
	for (int i = 0; i < n; i++) {
		bool check = true;
		for (int j = 0; j < col; j++) {
			board[col] = i;
			if (board[j] == board[col] || j - col == board[j] - board[col] || j - col == board[col] - board[j]) {
				check = false;
				break;
			}
		}
		if (check) {
			NQueens(col + 1);
		}
	}

}

int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		board[0] = i;
		NQueens(1);
	}
	cout << dist;
}