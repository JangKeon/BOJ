#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct job {
	int time;
	int require;
};

struct compare {
	bool operator()(job a, job b) {
		if (a.require < b.require) {
			return true;
		}
		else return false;
	}
};

priority_queue <job> pq;

int main(void) {
	int N, t, r;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> t >> r;
		pq.push({ t, r });
	}

	for (int i = 0; i < N; i++) {
		cout << pq.top().time << '\n';
		pq.pop();
	}
}