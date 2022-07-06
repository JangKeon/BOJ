#include <iostream>
#include <queue>
using namespace std;

priority_queue <int, vector <int>, greater<int>> MinHeap;
priority_queue <int> MaxHeap;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N, num;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num;
		if (MaxHeap.size() == 0) {
			MaxHeap.push(num);
		}
		else {
			if (MaxHeap.size() > MinHeap.size()) {
				MinHeap.push(num);
			}
			else {
				MaxHeap.push(num);
			}
			if (MaxHeap.top() > MinHeap.top()) {
				int Max = MaxHeap.top();
				int Min = MinHeap.top();
				MaxHeap.pop();
				MinHeap.pop();
				MinHeap.push(Max);
				MaxHeap.push(Min);
			}
		}
		cout << MaxHeap.top() << '\n';
	}
	
}