#include <iostream>
#include <queue>
using namespace std;

int main(void) {
	int N, num;
	int arr[10001] = {0, };
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num;
		arr[num]++;
	}
	for (int i = 0; i < 10001; i++) {
		for (int j = 0; j < arr[i]; j++) {
			cout << i << '\n';
		}
	}
}