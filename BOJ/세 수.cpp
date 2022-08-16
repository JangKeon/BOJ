#include <iostream>
#include <queue>
using namespace std;

int main(void) {
	priority_queue <int> pq;
	int num;
	for (int i = 0; i < 3; i++) {
		cin >> num;
		pq.push(num);
	}
	pq.pop();
	cout << pq.top();
}