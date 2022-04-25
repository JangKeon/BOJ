#include <iostream>
using namespace std;
#define MAX 1000000000;


int main(void) {
	long long X, Y;
	cin >> X >> Y;

	long long left = 0, right = MAX;
	int now = (Y * 100) / X;
	if (now >= 99) {
		cout << -1;
		return 0;
	}
	else {
		while (left <= right) {
			long long middle = (left + right) / 2;
			int change = (100 * (Y + middle)) / (X + middle);
			if (now >= change) {
				left = middle + 1;
			}
			else {
				right = middle - 1;
			}
		}
		cout << left;
	}
}