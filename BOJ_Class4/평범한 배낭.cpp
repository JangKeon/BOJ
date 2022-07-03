#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[101][100001];

int main(void) {
	int N, K, W, V;
	vector <pair<int, int>> vec;
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> W >> V;
		vec.push_back(make_pair(W, V));
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= K; j++) {
			if (i == 0) {
				if (vec[i].first <= j)	dp[i][j] = vec[i].second;
				continue;
			}
			if (vec[i].first <= j) {
				dp[i][j] = max(dp[i - 1][j], vec[i].second + dp[i - 1][j - vec[i].first]);
			}
			else dp[i][j] = dp[i - 1][j];
		}
	}
	cout << dp[N - 1][K] << '\n';
}