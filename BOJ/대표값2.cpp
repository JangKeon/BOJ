#include <iostream>
#include <queue>
using namespace std;

int main(void) {
	int sum = 0, mid = 0;
	priority_queue <int> pq;
	int num;
	for (int i = 0; i < 5; i++) {
		cin >> num;
		pq.push(num);
	}
	while (!pq.empty()) {
		sum += pq.top();
		mid++;
		if (mid == 3) {
			mid = pq.top();
		}
		pq.pop();
	}
	cout << sum / 5 << '\n' << mid - 2 << '\n';
}