#include <iostream>
using namespace std;

int main(void) {
	int N;
	int dp[1001] = { 0, 1, 3, 5, 11, };
	for (int i = 5; i <= 1000; i++) {
		dp[i] = ((dp[i - 2] * 2) + dp[i - 1]) % 10007;
	}
	cin >> N;
	cout << dp[N];
}