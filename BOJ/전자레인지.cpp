#include <iostream>
using namespace std;

int main(void) {
	int time, A = 0, B = 0, C = 0;
	cin >> time;
	while (time >= 300) {
		A++;
		time -= 300;
	}
	while (time >= 60) {
		B++;
		time -= 60;
	}
	while (time >= 10) {
		C++;
		time -= 10;
	}
	if (time != 0) {
		cout << -1;
	}
	else {
		cout << A << ' ' << B << ' ' << C;
	}
}