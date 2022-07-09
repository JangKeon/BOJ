#include <iostream>
#include <queue>
using namespace std;

int arr[1001];

struct pizza {
	int time;
	int slice;
};

int main(void) {
	int N, s;
	cin >> N;
	queue <pizza> que;
	for (int i = 0; i < N; i++) {
		cin >> s;
		que.push({i, s});
	}
	int t = 1;
	while (!que.empty()) {
		int num = que.front().slice;
		int index = que.front().time;
		if (num == 1) {
			arr[que.front().time] = t;
			que.pop();
		}
		else {
			que.pop();
			que.push({ index, num - 1 });
		}
		t++;
	}
	for (int i = 0; i < N; i++) {
		cout << arr[i] << ' ';
	}
}