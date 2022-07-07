#include <iostream>
using namespace std;

int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}


int main(void) {
	int A, B, C, D;
	cin >> A >> B >> C >> D;
	int up, down;
	down = B * D;
	up = (A * D) + (C * B);
	int temp = gcd(down, up);
	int res_up = up / temp;
	int res_down = down / temp;
	cout << res_up << ' ' << res_down;
}