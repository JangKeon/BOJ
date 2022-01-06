#include <stdio.h>
#include <stdlib.h>
#include <iostream>
int main() {

	int N, divide, result = 0, a = 0;
	std::cin >> N;
	int count = 0, add = 1;

	while (N > add) {
		add += 6 * count;
		count++;
	}
	if (N == 1)	count = 1;
	std::cout << count;
	return 0;
}