#include <iostream>
using namespace std;

int main(void) {
	int T;
	cin >> T;
	bool toggle = false;
	for (int i = 0; i < T; i++) {
		if (toggle) cout << ' ';
		for (int j = 0; j < T; j++) {
			cout << "* ";
		}
		cout << '\n';
		toggle = !toggle;
	}
}