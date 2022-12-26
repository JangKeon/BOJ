#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	priority_queue <int> que;
	int N, x;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x;
		if (x == 0) {
			if (que.empty()) {
				cout << '0' << '\n';
			}
			else {
				cout << que.top() << '\n';
				que.pop();
			}
		}
		else {
			que.push(x);
		}
	}
}