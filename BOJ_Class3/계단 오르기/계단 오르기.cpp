#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	int N, score;
	int dp[301] = {  };
	vector <int> vec;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> score;
		vec.push_back(score);
	}
	int res = 0, count = 0;
	dp[0] = 0;
	dp[1] = vec[0];
	dp[2] = vec[0] + vec[1];
	dp[3] = max(vec[0], vec[1]) + vec[2];

	for (int i = 4; i <= N ; i++) {
		dp[i] = max(dp[i - 2], dp[i - 3] + vec[i - 2]) + vec[i - 1];
	}
	cout << dp[N];
}