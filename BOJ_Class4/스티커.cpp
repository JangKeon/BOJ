#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	int T, n, num;
	int dp[100001], location[100001];
	vector <int> score[2];
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> n;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < n; j++) {
				cin >> num;
				score[i].push_back(num);
			}
		}
		dp[1] = max(score[0][0], score[1][0]); // index 저장 필요
		if (dp[1] == score[0][0]) {
			location[1] = 0;
		}
		else location[1] = 1;
		dp[2] = max(score[0][0] + score[1][1], score[0][1] + score[1][0]);
		if (dp[2] == score[0][0] + score[1][1]) {
			location[2] = 1;
		}
		else location[2] = 0;
		for (int i = 3; i <= 100000; i++) {
			int a = dp[i - 2] + score[~location[i - 1]][i - 1] + score[location[i - 1]][i];
			int b = dp[i - 2] + score[~location[i - 1]][i];
			dp[n] = max(a, b);
			if (dp[n] == dp[n - 2] + score[~location[i - 1]][n]) {
				location[i] = ~location[i - 2];
			}
			else location[i] = location[i - 2];
		}
		cout << dp[n];
	}
}