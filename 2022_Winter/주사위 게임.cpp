#include <iostream>
using namespace std;

int main(void) {
	int one = 100, two = 100;
	int n;
	cin >> n;
	for (int i = 0; i < 4; i++) {
		int A, B;
		cin >> A >> B;
		if (A > B) {
			two = two - A;
		}
		else if (A < B) {
			one = one - B;
		}
	}
	cout << one << '\n' << two;
}