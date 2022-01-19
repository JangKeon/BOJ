#include <iostream>
#include <string>
#include <queue>
using namespace std;
#pragma warning(disable:4996)

int main() {
	int N, num;
	scanf("%d", &N);
	queue <int> que;
	for (int i = 0; i < N; i++) {
		que.push(i + 1);
	}

	while (que.size() != 1) {
		que.pop();
		num = que.front();
		que.pop();
		que.push(num);
	}
	printf("%d", que.front());

	return 0;
}