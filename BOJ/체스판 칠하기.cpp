#include <iostream>
using namespace std;
#pragma warning(disable:4996)

int Min(int a, int b) {
	if (a >= b) {
		return b;
	}
	else {
		return a;
	}
}

int main() {
	char arr_black[8][8] = 
		{ {'B', 'W','B', 'W','B', 'W','B', 'W'},
		{'W', 'B', 'W','B', 'W','B', 'W','B'}, 
		{'B', 'W','B', 'W','B', 'W','B', 'W'}, 
		{'W', 'B', 'W','B', 'W','B', 'W','B'},
		{'B', 'W','B', 'W','B', 'W','B', 'W'}, 
		{'W', 'B', 'W','B', 'W','B', 'W','B'},
		{'B', 'W','B', 'W','B', 'W','B', 'W'},
		{'W', 'B', 'W','B', 'W','B', 'W','B'} };

	char arr_white[8][8] =
		{ {'W', 'B', 'W','B', 'W','B', 'W','B'},
		{'B', 'W','B', 'W','B', 'W','B', 'W'},
		{'W', 'B', 'W','B', 'W','B', 'W','B'},
		{'B', 'W','B', 'W','B', 'W','B', 'W'},
		{'W', 'B', 'W','B', 'W','B', 'W','B'},
		{'B', 'W','B', 'W','B', 'W','B', 'W'},
		{'W', 'B', 'W','B', 'W','B', 'W','B'},
		{'B', 'W','B', 'W','B', 'W','B', 'W'} };

	int N, M;
	scanf("%d %d", &N, &M);
	char c;
	char** arr;
	arr = (char**)malloc(sizeof(char*) * N);
	for (int i = 0; i < N; i++) {
		arr[i] = (char*)malloc(sizeof(char) * M);
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> c;
			arr[i][j] = c;
		}
	}

	int black_num = 0, white_num = 0, min = 0, result = 99999;
	for (int k = 0; k <= N - 8; k++) {
		for (int l = 0; l <= M - 8; l++) {
			for (int i = 0; i < 8; i++) {
				for (int j = 0; j < 8; j++) {
					if (arr[k+i][l+j] != arr_black[i][j]) {
						black_num++;
					}
					if (arr[k+i][l+j] != arr_white[i][j]) {
						white_num++;
					}
				}
			}
			min = Min(black_num, white_num);
			if (result > min) {
				result = min;
			}
			black_num = 0;
			white_num = 0;
		}
	}
	cout << result << '\n';
	for (int i = 0; i < N; i++) {
		free(arr[i]);
	}
	free(arr);

	return 0;
}