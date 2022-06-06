#include <iostream>
using namespace std;

int main(void) {
	int dp[91] = { 0, 1, 1, 2, 3, 5, };
	for (int i = 6; i < 91; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	int N;
	cin >> N; 
	cout << dp[N]
}