#include <iostream>
using namespace std;

int main(void) {
	int ans[11];
	ans[1] = 1;
	ans[2] = 2;
	ans[3] = 4;
	ans[4] = 7;
	for (int i = 5; i < 11; i++) {
		ans[i] = ans[i - 1] + ans[i - 2] + ans[i - 3];
	}
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		cout << ans[num] << '\n';
	}
}