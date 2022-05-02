#include <iostream>
using namespace std;

int main(void) {
	string a;
	cin >> a;
	for (int i = 0; i < a.size(); i++) {
		a[i] = a[i] + ('A' - 'a');
	}
	cout << a;
}