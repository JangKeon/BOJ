#include <iostream>
#include <vector>
using namespace std;

int arr[100001];
int dp[100001];

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int N, M, i, j, num;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> num;
		arr[i] = num;
	}
	dp[1] = arr[1];
	for (int i = 2; i <= N; i++) {
		dp[i] = dp[i - 1] + arr[i];
	}

	for (int a = 0; a < M; a++) {
		cin >> i >> j;
		cout << dp[j] - dp[i - 1] << '\n';
	}
}