#include <iostream>
#include <string>
using namespace std;

int main(void) {
	string a, b;
	cin >> a >> b;
	string r_a, r_b;
	for (int i = 2; i >= 0; i--) {
		r_a.push_back(a[i]);
		r_b.push_back(b[i]);
	}
	int A = stoi(r_a), B = stoi(r_b);
	if (A > B) {
		cout << A;
	}
	else cout << B;
}