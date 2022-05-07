#include <iostream>
#include <algorithm>
using namespace std;


int main(void) {
    int N, res = 0;
    int arr[1001], dp[1001] = { 0, };
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    fill(dp, dp + 1001, 1);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j < i; j++) {
            if (arr[i] > arr[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        res = max(res, dp[i]);
    }

    cout << res;
}

