#include <iostream>
using namespace std;

struct H {
	unsigned long long a, b, c, d;
};

H mul(H A, H B) {
	return{
		(A.a * B.a + A.b * B.c) % 1000000007,
		(A.a * B.b + A.b * B.d) % 1000000007,
		(A.c * B.a + A.d * B.c) % 1000000007,
		(A.c * B.b + A.d * B.d) % 1000000007,
	};
}

unsigned long long N;

int main(void) {
	cin >> N;
	H multiply = { 1, 1, 1, 0 };
	H res = { 1, 0, 0, 1 };
	for (; N > 0; N = N >> 1) {
		if (N & 1) {
			res = mul(res, multiply);
		}
		multiply = mul(multiply, multiply);
	}
	cout << res.b;
}