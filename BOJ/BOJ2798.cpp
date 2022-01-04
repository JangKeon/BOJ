#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int main() {
	int N = 0, M = 0;
	int add = 0, result = 0;
	scanf("%d %d", &N, &M);
	int* val = (int*)malloc(sizeof(int) * N);
	
	for (int i = 0; i < N; i++) {
		scanf("%d", &val[i]);
	}

	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			for (int k = j + 1; k < N; k++) {
				add = val[i] + val[j] + val[k];
				if (add > result && add <= M) {
					result = add;
				}
			}
		}
	}

	printf("%d", result);
	return 0;
}