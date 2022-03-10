#include <iostream>
using namespace std;

int main(void) {
	int N;
	cin >> N;
	int cnt2 = 0, cnt5 = 0;
	for (int i = 1; i <= N; i++) {
		int num = i;
		while (true) {
			if (num % 2 == 0 && num % 5 == 0) {
				cnt2++; cnt5++;
				num /= 10;
			}
			else if (num % 2 == 0) {
				cnt2++;
				num /= 2;
			}
			else if (num % 5 == 0) {
				cnt5++;
				num /= 5;
			}
			else break;
		}
	}
	if (cnt2 > cnt5) cout << cnt5;
	else cout << cnt2;
}