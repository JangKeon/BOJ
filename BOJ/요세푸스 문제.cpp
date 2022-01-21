#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
#pragma warning(disable:4996)

int main(void) {
	queue <int> que;
	queue <int> res;
	int N, K;
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++) {
		que.push(i + 1);
	}
	int a = 0;
	while (!que.empty()) {
		a++;
		if (a == K) {
			res.push(que.front());
			que.pop();
			a = 0;
		}
		else {
			que.push(que.front());
			que.pop();
		}
	}
	cout << '<';
	while (!res.empty()) {
		if (res.size() == 1) {
			cout << res.front();
		}
		else cout << res.front() << ',' << ' ';
		res.pop();
	}
	cout << '>';
}