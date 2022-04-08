#include <iostream>
#include <deque>
#define Max 100000
using namespace std;

bool visit[Max + 1];

int main(void) {
	int N, K;
	deque <pair<int, int>> deq;
	cin >> N >> K;
	deq.push_front(make_pair(N, 0));
	visit[N] = true;
	while (!deq.empty()) {
		int now = deq.front().first;
		int time = deq.front().second;
		deq.pop_front();
		visit[now] = true;

		if (now == K) {
			cout << time;
			break;
		}

		int up = now * 2;
		int left = now - 1;
		int right = now + 1;

		if (up <= Max && !visit[up]) {
			deq.push_front(make_pair(up, time));
		}
		if (left >= 0 && !visit[left]) {
			deq.push_back(make_pair(left, time + 1));
		}
		if (right <= Max && !visit[right]) {
			deq.push_back(make_pair(right, time + 1));
		}

	}
}