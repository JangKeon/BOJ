#include <iostream>
using namespace std;

long long N, M, Max = 0, Min = 0;
long long tree[1000001];

int main(void) {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> tree[i];
		if (tree[i] > Max) {
			Max = tree[i];
		}
	}

	long long mid;
	long long ans = 0;

	while (Min <= Max) {
		mid = (Max + Min) / 2;
		long long result = 0;
		for (int i = 0; i < N; i++) {
			if (tree[i] > mid) {
				result += (tree[i] - mid);
			}
		}
		if (result >= M) {
			Min = mid + 1;
			ans = mid;
		}
		else {
			Max = mid - 1;
		}
	}
	cout << ans;
}