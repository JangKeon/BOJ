#include <iostream>
using namespace std;

int main(void) {
	int N;
	cin >> N;
	while (N != 1) {
		for (int i = 2; i < 50000000; i++) {
			if (N % i == 0) {
				N /= i;
				cout << i << '\n';
				break;
			}
		}
	}
}