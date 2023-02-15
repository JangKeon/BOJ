#include <stdio.h>
#include <iostream>
using namespace std;

int main(void) {
	int map[9][9];
	int max = -1, x, y;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> map[i][j];
			if (max < map[i][j] ) {
				max = map[i][j];
				x = i;
				y = j;
			}
		}
	}
	cout << max << '\n' << x + 1 << ' ' << y + 1;
}