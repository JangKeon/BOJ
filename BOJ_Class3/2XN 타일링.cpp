#include <iostream>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int ans[1001] = { 0, 1, 2 }, res[1001] = {0, 1, 2};
	int N;
	cin >> N;
	for (int i = 3; i <= N; i++) {
		ans[i] = (ans[i - 1] + ans[i - 2]) % 10007;
	}
	cout << ans[N];
}