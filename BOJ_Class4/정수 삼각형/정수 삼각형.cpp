#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> triangle[501];
int dp[501][501];

int main(void) {
	int N, num;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < i; j++) {
			cin >> num;
			triangle[i].push_back(num);
		}
	}
	dp[1][0] = triangle[1][0];

	for (int i = 2; i <= N; i++) {
		for (int j = 0; j < i; j++) {
			
			if (j == 0) {
				dp[i][j] = dp[i - 1][j] + triangle[i][j];
			}

			else if (j == i - 1) {
				dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
			}
			
			else {
				dp[i][j] = max(dp[i - 1][j] + triangle[i][j], dp[i - 1][j - 1] + triangle[i][j]);
			}
		}
	}

	int result = 0;
	
	for (int i = 0; i < N; i++) {
		if (dp[N][i] > result) {
			result = dp[N][i];
		}
	}
	cout << result;
}
