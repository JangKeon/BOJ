#include <iostream>
using namespace std;

int main(void) {
	long long dp[102] = { 0, 1, 1, 1, 2 };

	for (int i = 5; i < 102; i++) {
		dp[i] = dp[i - 3] + dp[i - 2];
	}

	int T, N;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;
		cout << dp[N] << '\n';
	}
}