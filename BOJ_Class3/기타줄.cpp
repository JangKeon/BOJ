#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main(void) {
	int N, M;
	cin >> N >> M;
	priority_queue <int, vector<int>, greater<>> package;
	priority_queue <int, vector<int>, greater<>> one;
	int p, o;
	for (int i = 0; i < M; i++) {
		cin >> p >> o;
		package.push(p);
		one.push(o);
	}
	int num = N / 6;
	int remain = N % 6;
	int result = min((num + 1) * package.top(), (num * package.top()) + remain * one.top());
	result = min(result, one.top() * N);
	cout << result;
}