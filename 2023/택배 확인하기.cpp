#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[20000001];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	vector <int> have;
	int N, M, num;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num;
		arr[num + 10000000] = 1;
	}
	sort(have.begin(), have.end());
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> num;
		if (arr[num + 10000000]) {
			cout << 1 << ' ';
		}
		else
		{
			cout << 0 << ' ';
		}
	}
}