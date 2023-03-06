#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int dp[100001];
int visited[100001];
queue <int> que;
int N, K;

void bfs() {
	while (!que.empty()) {
		int x = que.front();
		que.pop();
		for (int nxt : {x - 1, x + 1, x * 2}) {
			if (nxt < 0 || nxt > 100000) {
				continue;
			}
			if (visited[nxt])	continue;
			visited[nxt] = 1;
			que.push(nxt);
			dp[nxt] = dp[x] + 1;
		}
	}
}

int main(void) {
	cin >> N >> K;
	if (N >= K) {
		cout << N - K;
		return 0;
	}
	dp[N] = 0;
	visited[N] = 1; 
	que.push(N);
	bfs();
	cout << dp[K];
}