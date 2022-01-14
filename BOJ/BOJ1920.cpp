#include <iostream>
#include <algorithm>
using namespace std;
#pragma warning(disable:4996)

int main() {
	int* vec;
	int N, M, num, isIn;
	scanf("%d", &N);
	vec = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &num); 
		vec[i] = num;
	}
	sort(vec, vec + N);
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		scanf("%d", &isIn);
		if (binary_search(vec, vec + N, isIn)) {
			printf("1\n");
		}
		else {
			printf("0\n");
		}
	}
}
