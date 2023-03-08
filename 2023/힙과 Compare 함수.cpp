#include <iostream>
#include <queue>
#include <stdlib.h>
using namespace std;

struct compare {
	bool operator()(int a, int b) {
		if (abs(a) == abs(b)) {
			return a > b;
		}
		else return abs(a) > abs(b);
	}
};

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	priority_queue <int, vector <int>, compare> pq;
	int N, exc, res;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> exc;
		if (exc == 0) {
			if (pq.empty()) {
				cout << "0\n";
			}
			else {
				cout << pq.top() << '\n';
				pq.pop();
			}
		}
		else {
			pq.push(exc);
		}
	}
}