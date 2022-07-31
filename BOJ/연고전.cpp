#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	int T;
	cin >> T;
	for (int u = 0; u < T; u++) {
		int a, b, K = 0, Y = 0;
		for (int i = 0; i < 9; i++) {
			cin >> a >> b;
			Y += a;
			K += b;
		}
		if (K > Y)	cout << "Korea\n";
		if (K == Y) cout << "Draw\n";
		if (K < Y)	cout << "Yonsei\n";
	}
}