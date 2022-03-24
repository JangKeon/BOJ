#include <iostream>
using namespace std;

int main(void) {
	int dp[5002] = {0,-1, -1, 1, -1, 1, 2, -1, 2, 3, 2};
	int N;
	for (int i = 10; i <= 5000; i++) {
		if (dp[i - 3] == -1) {
			dp[i] = dp[i - 5] + 1;
		}
		else if (dp[i - 5] == -1) {
			dp[i] = dp[i - 3] + 1;
		}
		else {
			dp[i] = min(dp[i - 3] + 1, dp[i - 5] + 1);
		}
	}
	cin >> N;
	cout << dp[N];
}