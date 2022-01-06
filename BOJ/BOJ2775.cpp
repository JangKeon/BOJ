#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#pragma warning(disable:4996)


int main() {

	int T, K, N, num = 0;
	int arr[100][100];
	std::cin >> T;
	for (int j = 0; j < T; j++) {
		std::cin >> K >> N;
		for (int i = 0; i < N; i++) {
			arr[0][i] = i+1;
		}

		for (int i = 0; i < K + 1; i++) {
			arr[i][0] = 1;
		}

		for (int i = 1; i < K + 1; i++) {
			for (int a = 1; a < N; a++) {
				arr[i][a] = arr[i - 1][a] + arr[i][a - 1];
			}
		}
		std::cout << arr[K][N - 1] << "\n";
		printf("%d\n", arr[K][N - 1]);
		
	}

	return 0;
}