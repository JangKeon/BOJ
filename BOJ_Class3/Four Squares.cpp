#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int dp[50001];

int main(void) {
	fill(dp, dp + 50001, 5);
	for (int i = 1; i <= 223; i++) {
		dp[i * i] = 1;
	}
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j * j < i; j++) {
			dp[i] = min(dp[i], dp[j * j] + dp[i - j * j]);
		}
	}

	cout << dp[N];
}