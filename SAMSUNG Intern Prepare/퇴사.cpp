#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct job {
	int day;
	int score;
};

int dp[25];
vector <job> Job;

int main(void) {
	int N, day, score;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> day >> score;
		Job.push_back({ day, score });
	}
	for (int i = 0; i < N; i++) {
		dp[i + 1] = max(dp[i], dp[i + 1]);
		dp[i + Job[i].day] = max(dp[i + Job[i].day], dp[i] + Job[i].score);
	}
	cout << dp[N];
}