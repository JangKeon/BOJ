#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	string a, res;
	cin >> a;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] >= 'a' && a[i] <= 'z') {
			res += a[i] - ('a' - 'A');
		}
		else {
			res += a[i] + ('a' - 'A');
		}
	}
	cout << res;
}