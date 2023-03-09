#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int dp[27];
int visited[27];

int main(void) {
	int N;
	string S;
	cin >> N >> S;
	for (int i = 0; i < S.size(); i++) {
		int var = 0;
		memset(visited, 0, sizeof(visited));
		for (int j = i; j < S.size(); j++) {
			int temp = S[j] - 'a';
			if (!visited[temp]) {
				var++;
				visited[temp] = 1;
			}
			dp[var] = max(dp[var], j - i + 1);
		}
	}
	for (int i = 1; i < 27; i++) {
		cout << dp[i] << '\n';
	}
}