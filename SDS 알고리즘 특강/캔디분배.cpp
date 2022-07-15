#include <iostream>
using namespace std;

long long gcd(long long a, long long b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}

int main(void) {
	int T;
	cin >> T;
	for (int u = 0; u < T; u++) {
		long long K, C;
		cin >> K >> C;
		long long gc = gcd(-K, C);
		if (gc != 1 && gc != -1) {
			cout << "IMPOSSIBLE" << '\n';
		}
        else {
            long long s1 = 1, t1 = 0, r1 = K;
            long long s2 = 0, t2 = 1, r2 = C;

            while (r2 > 1) {
                long q = r1 / r2;
                long temp = 0;
                temp = s2;
                s2 = s1 - q * s2;
                s1 = temp;

                temp = t2;
                t2 = t1 - q * t2;
                t1 = temp;
                temp = r2;
                r2 = r1 - q * r2;
                r1 = temp;
            }

            while (s2 >= 0 || t2 <= 0) {
                s2 = s2 - C;
                t2 = t2 + K;
            }
            if (t2 > 1000000000L) {
                printf("IMPOSSIBLE\n");
            }
            else {
                printf("%d\n", t2);
            }
        }
	}
}