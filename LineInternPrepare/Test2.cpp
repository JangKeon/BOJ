#include <string>
#include <vector>
#include <iostream>

using namespace std;

int dp[2001];

int solution(int n, vector<int> times) {
    fill(dp, dp + 2001, 9999999);
    dp[1] = 0;
    dp[2] = times[0];
    for (int i = 3; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            if (i - j - 1 < j) {
                dp[i] = min(dp[i], dp[j] + times[i - j - 1]);
            }
        }
    }
    int answer = dp[n];
    cout << answer;
    return answer;
}