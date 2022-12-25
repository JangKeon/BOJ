#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T, N;
	cin >> T;
	for (int k = 0; k < T; k++) {
		int size = 0;
		unordered_map <int, int> visited;
		priority_queue <int> MaxHeap;
		priority_queue <int, vector <int>, greater<>> MinHeap;
		cin >> N;
		for (int i = 0; i < N; i++) {
			char opt;
			int num;
			cin >> opt >> num;
			if (!size) {
				MaxHeap = priority_queue <int>();
				MinHeap = priority_queue <int, vector <int>, greater<>>();
			}
			if (opt == 'I') {
				MaxHeap.push(num);
				MinHeap.push(num);
				size++;
				visited[num]++;
			}
			else {
				if (!size)	continue;
				else if (opt == 'D' && num == 1) {
					while (!MaxHeap.empty() && !visited[MaxHeap.top()]) {
						MaxHeap.pop();
					}
					visited[MaxHeap.top()]--;
					MaxHeap.pop();
					size--;
				}
				else if (opt == 'D' && num == -1) {
					while (!MinHeap.empty() && !visited[MinHeap.top()]) {
						MinHeap.pop();
					}
					visited[MinHeap.top()]--;
					MinHeap.pop();
					size--;
				}
			}
			while (!MaxHeap.empty() && !visited[MaxHeap.top()]) {
				MaxHeap.pop();
			}
			while (!MinHeap.empty() && !visited[MinHeap.top()]) {
				MinHeap.pop();
			}
		}
		if (size == 0) {
			cout << "EMPTY\n";
		}
		else {
			cout << MaxHeap.top() << ' ' << MinHeap.top() << '\n';
		}
	}
}
