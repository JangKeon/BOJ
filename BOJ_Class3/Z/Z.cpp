#include <iostream>
#include <math.h>
#include <stdlib.h>
using namespace std;

int zx[4] = { 0, 0, 1, 1 };
int zy[4] = { 0, 1, 0, 1 };
int num = 0;

void Draw(int x, int y, int ** arr) {
	for (int i = 0; i < 4; i++) {
		arr[x + zx[i]][y + zy[i]] = num;
		num++;
	}
}

void Cut(int x, int y, int size, int **arr) {
	if (size > 2) {
		Cut(x, y, size / 2, arr);
		Cut(x, y + size / 2, size / 2, arr);
		Cut(x + size / 2, y, size / 2, arr);
		Cut(x + size / 2, y + size / 2, size / 2, arr);
	}
	else Draw(x, y, arr);
}

int main(void) {
	int N, r, c;
	cin >> N >> r >> c;
	int size = pow(2, N);
	int ** arr = (int**)malloc(sizeof(int*) * size);
	for (int i = 0; i < size; i++) {
		arr[i] = (int*)malloc(sizeof(int) * size);
	}

	Cut(0, 0, size, arr);
	cout << arr[r][c];
}