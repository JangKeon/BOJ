#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[101];

struct P {
	int H;
	int J;
};

bool compare(P a, P b) {
	if (a.H == b.H) {
		return a.J > b.J;
	}
	return a.H < b.H;
}

int main(void) {
	vector <P> vec;
	int N, health[20], joy[20];
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> health[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> joy[i];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 100; j >= health[i]; j--) {
			dp[j] = max(dp[j - health[i]] + joy[i], dp[j]);
		}
	}
	int M = 0;
	for (int i = 1; i < 100; i++) {
		if (M < dp[i]) M = dp[i];
	}
	cout << M;
}