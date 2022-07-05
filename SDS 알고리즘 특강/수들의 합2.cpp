#include <iostream>
using namespace std;

int num[10001];

int main(void) {
	int N, M, a;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> a;
		num[i] = a;
	}
	int result = 0;
	int lft = 0, right = 0, sum = 0;
	while (1) {
		if (sum > M) {
			sum -= num[lft];
			lft++;
		}
		else {
			if (right == N) {
				break;
			}
			sum += num[right];
			right++;
		}
		if (sum == M) {
			result++;
		}

	}
	cout << result;

}