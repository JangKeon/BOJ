#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int cost[1001][3];
int dp[1001][3];

int result(int a, int b, int c) {
	int min = 99999;
	if (min > a) {
		min = a;
	}
	if (min > b) {
		min = b;
	}
	if (min > c) {
		min = c;
	}
	return min;
}

int main(void) {
	int N, r, g, b;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> cost[i][j];
		}
	}

	for (int i = 1; i <= N; i++) {
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + cost[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + cost[i][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + cost[i][2];
	}
	int res = result(dp[N][0], dp[N][1], dp[N][2]);
	cout << res << '\n';
}