#include <iostream>
#include <math.h>
using namespace std;

int r, c, result;

void Z(int x, int y, int size) {
	if (x == r && y == c) {
		cout << result;
		return;
	}
	if (r < x + size && r >= x && c < y + size && c >= y) {
		Z(x, y, size >> 1);
		Z(x, y + (size >> 1), size >> 1);
		Z(x + (size >> 1), y, size >> 1);
		Z(x + (size >> 1), y + (size >> 1), size >> 1);
	}
	else result += size * size;
}

int main(void) {
	int N;
	cin >> N >> r >> c;
	Z(0, 0, (1 << N));
	
}