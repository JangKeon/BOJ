#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

int dp[2][100001], score[2][100001];

int main(void) {
	int T, n;
	cin >> T;
	for (int i = 0; i < T; i++) {
		memset(score, 0, sizeof(score));
		memset(dp, 0, sizeof(dp));
		cin >> n;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < n; j++) {
				cin >> score[i][j];
			}
		}
		dp[0][0] = score[0][0];
		dp[1][0] = score[1][0];
		dp[0][1] = score[1][0] + score[0][1];
		dp[1][1] = score[0][0] + score[1][1];

		for (int i = 2; i < n; i++) {
			dp[0][i] = max(dp[1][i - 2], dp[1][i - 1]) + score[0][i];
			dp[1][i] = max(dp[0][i - 2], dp[0][i - 1]) + score[1][i];
		}
		cout << max(dp[0][n - 1], dp[1][n - 1]) << '\n';
	}
}