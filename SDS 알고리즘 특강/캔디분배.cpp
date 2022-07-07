#include <iostream>
using namespace std;

int s, t, r, q;

int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}

int Euclid(int a, int b) {
	
	
}

int main(void) {
	int T;
	cin >> T;
	for (int u = 0; u < T; u++) {
		int K, C;
		cin >> K >> C;
		int gc = gcd(-K, C);
		if (gc != 1 && gc != -1) {
			cout << "IMPOSSIBLE" << '\n';
		}
		else {
			K /= gc;
			C /= gc;
			Euclid(-K, C);
		}
	}
}