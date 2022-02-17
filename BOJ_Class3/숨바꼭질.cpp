#include <iostream>
#include <queue>
#include <vector>
using namespace std;

bool check[100001];
int res[100001];

int main(void) {
	int x, point;
	cin >> x >> point;
	check[x] = true;
	res[x] = 0;
	queue <int> que;
	que.push(x);
	while (!que.empty()) {
		int now = que.front();
		que.pop();
		if (now - 1 >= 0) {
			if (check[now - 1] == false) {
				que.push(now - 1);
				check[now - 1] = true;
				res[now - 1] = res[now] + 1;
			}
		}
		if (now + 1 < 100001) {
			if (check[now + 1] == false) {
				que.push(now + 1);
				check[now + 1] = true;
				res[now + 1] = res[now] + 1;
			}
		}
		if ((now << 1) < 100001) {
			if (check[now << 1] == false) {
				que.push(now << 1);
				check[now << 1] = true;
				res[now << 1] = res[now] + 1;
			}
		}
	}

	cout << res[point];
}