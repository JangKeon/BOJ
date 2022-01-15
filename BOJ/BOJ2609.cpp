#include <iostream>
using namespace std;
#pragma warning(disable:4996)

int Max(int a, int b) {
	if (a >= b) {
		return a;
	}
	else return b;
}

int main() {
	int N, M;
	scanf("%d %d", &N, &M);
	int num = Max(N,M);
	while (num > 0) {
		if (N % num == 0 && M % num == 0) {
			printf("%d\n", num);
			break;
		}
		else num--;
	}
	num = Max(N, M);
	while (num < 100000000) {
		if (num % N == 0 && num % M == 0) {
			printf("%d\n", num);
			break;
		}
		else num++;
	}

}