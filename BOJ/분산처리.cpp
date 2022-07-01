#include <iostream>
using namespace std;

int main(void) {
	int T;
	cin >> T;
	for (int u = 0; u < T; u++) {
		int a, b, num, res;
		cin >> a >> b;
		res = 1;
		while (b != 0) {
			b--;
			res = (res * a) % 10;
		}
		if (res == 0) {
			cout << 10 << '\n';
		}
		else  cout << res << '\n';
	}
}