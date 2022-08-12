#include <iostream>
using namespace std;

int main(void) {
	int T;
	cin >> T;
	for (int u = 0; u < T; u++) {
		int N, D, v, f, c, res = 0;
		cin >> N >> D;
		for (int k = 0; k < N; k++) {
			cin >> v >> f >> c;
			if ((double)f / c * (double)v >= D) {
				res++;
			}
		}
		cout << res << '\n';
	}
}