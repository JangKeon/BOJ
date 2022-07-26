#include <iostream>
#include <vector>
using namespace std;

long long a, b, c, k;

long long mul(long long b) {
	if (b == 0)	return 1;
	if (b == 1)	return a % c;

	k = mul(b / 2) % c;
	if (b % 2 == 0)	return k * k % c;
	return k * k % c * a % c;
}

int main() {
	cin >> a >> b >> c;
	cout << mul(b) << '\n';
}