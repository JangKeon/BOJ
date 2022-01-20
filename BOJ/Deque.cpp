#include <iostream>
#include <deque>
using namespace std;
#pragma warning(disable:4996)

int main(void) {
	deque <int> dq;
	int N, num;
	string func;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		cin >> func;
		if (func == "push_front") {
			cin >> num;
			dq.push_front(num);
		}
		else if (func == "push_back") {
			cin >> num;
			dq.push_back(num);
		}
		else if (func == "pop_front") {
			if (dq.empty()) {
				printf("-1\n");
			}
			else {
				cout << dq.front() << '\n';
				dq.pop_front();
			}
		}
		else if (func == "pop_back") {
			if (dq.empty()) {
				printf("-1\n");
			}
			else {
				cout << dq.back() << '\n';
				dq.pop_back();
			}
		}
		else if (func == "empty") {
			if (dq.empty()) {
				printf("1\n");
			}
			else printf("0\n");
		}
		else if (func == "front") {
			if (dq.empty()) {
				printf("-1\n");
			}
			else cout << dq.front() << '\n';
		}
		else if (func == "back") {
			if (dq.empty()) {
				printf("-1\n");
			}
			else cout << dq.back() << '\n';
		}
		else if (func == "size") {
			cout << dq.size() << '\n';
		}
	}
}