#include <iostream>
#include <algorithm>
using namespace std;

string dp[101][101];

string sumString(string a, string b) {
	int sum = 0;
	string ans = "";
	
	while (!a.empty() || !b.empty() || sum != 0) {
		if (!a.empty()) {
			sum += a.back() - '0';
			a.pop_back();
		}

		if (!b.empty()) {
			sum += b.back() - '0';
			b.pop_back();
		}
		ans.push_back((sum % 10) + '0');
		sum = sum / 10;
	}
	reverse(ans.begin(), ans.end());
	return ans;
}

string Comb(int n, int m) {
	if (n == m || m == 0) {
		return "1";
	}
	if (dp[n][m] != "") {
		return dp[n][m];
	}

	dp[n][m] = sumString(Comb(n - 1, m), Comb(n - 1, m - 1));
	return dp[n][m];
}

int main(void) {
	int n, m;
	cin >> n >> m;
	cout << Comb(n, m);
}