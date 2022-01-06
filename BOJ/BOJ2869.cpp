#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#pragma warning(disable:4996)
# define Size 1000000000
int main() {
	int A, B, V, day, current = 0;
	scanf("%d %d %d", &A, &B, &V);

	if ((V - A) % (A - B) == 0) {
		printf("%d", (V - A) / (A - B) + 1);
	}
	else {
		printf("%d", (V - A) / (A - B) + 2);
	}

	return 0;
}