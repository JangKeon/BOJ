#include <iostream>
using namespace std;

int main(void) {
	int T;
	cin >> T;
	for (int u = 0; u < T; u++) {
		int A, B;
		cin >> A >> B;
		for (int i = 1; i <= 45000; i++) {
			int temp = A * i;
			if ((temp % B) == 0) {
				cout << temp << '\n';
				break;
			}
		}
	}
}