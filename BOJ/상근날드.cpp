#include <iostream>
using namespace std;

int main(void) {
	int a[3], b[2], min = 3000, result = 0;
	for (int i = 0; i < 3; i++) {
		cin >> a[i];
		if (a[i] < min) {
			min = a[i];
		}
	}
	result += min;
	min = 3000;
	for (int i = 0; i < 2; i++) {
		cin >> b[i];
		if (b[i] < min) {
			min = b[i];
		}
	}
	result += min;
	cout << result - 50;
}