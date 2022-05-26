#include <iostream>
#include <deque>
#define Max 100000
using namespace std;

bool visit[Max + 1];

int main(void) {
	int brown, cony, time = 0;
	deque <pair<int, int>> deq;
	cin >> brown >> cony;
	deq.push_front(make_pair(brown, 0));
	visit[brown] = true;
	while (1) {
		cony += time;

		for (int i = 0; i < deq.size(); i++) {
			int now = deq.front().first;
			int time = deq.front().second;

			deq.pop_front();
			visit[now] = true;

			if (now == cony) {
				cout << time - 1;
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
		time++;
	}
}