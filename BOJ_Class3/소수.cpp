#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	int M, N;
	cin >> M >> N;
	vector <int> res;
	for (int i = M; i <= N; i++) {
		bool isIn = true;
		int cnt = 0;
		for (int j = 1; j <= i; j++) {
			if (i % j == 0) {
				cnt++;
			}
		}
		if (cnt == 2) {
			res.push_back(i);
		}
	}

	if (res.size() == 0) {
		cout << -1;
	}
	else {
		int sum = 0, min = 987654321;
		for (int i = 0; i < res.size(); i++) {
			sum += res[i];
		}
		cout << sum << '\n' << res[0];
	}
}