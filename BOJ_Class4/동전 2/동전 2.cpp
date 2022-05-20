#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[100001];
vector <int> value;

int main(void) {
	int n, k;
	cin >> n >> k;
	fill(dp, dp + 10001, 987654321);
	int num;
	for (int i = 0; i < n; i++) {
		cin >> num;
		value.push_back(num);
		dp[num] = 1;
	}

	for (int i = 1; i <= k; i++) {
		for (int j = 0; j < value.size(); j++) {
			if (i - value[j] < 1) {
				continue;
			}
			dp[i] = min(dp[i], dp[i - value[j]] + 1);
		}
	}
	if (dp[k] == 987654321) {
		cout << -1 << '\n';
	}
	else {
		cout << dp[k] << '\n';
	}
}