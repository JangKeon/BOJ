#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	int K, D, A;
	char c;
	cin >> K >> c >> D >> c >> A;
	bool go = true;
	if (K + A < D) {
		go = false;
	}
	if (D == 0) {
		go = false;
	}
	if (go) {
		cout << "gosu\n";
	}
	else cout << "hasu\n";
}