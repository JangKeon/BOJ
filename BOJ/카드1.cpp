#include <iostream>
#include <queue>
using namespace std;

int main(void) {
	queue <int> que;
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		que.push(i);
	}

	while (que.size() > 1) {
		cout << que.front() << ' ';
		que.pop();
		int num = que.front();
		que.push(num);
		que.pop();
	}
	cout << que.front();
}