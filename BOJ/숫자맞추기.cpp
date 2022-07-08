#include <iostream>
using namespace std;

int main(void) {
	int num = 9999, index = 1;
	int n1, n2, n3, n4;
	bool is_even = false;
	while (1) {
		cin >> num;
		if (num == 0)	break;
		n1 = 3 * num;
		if (n1 % 2 == 0) {
			is_even = true;
			n2 = n1 / 2;
		}
		else { 
			n2 = (n1 + 1) / 2;
			is_even = false;
		}
		n3 = n2 * 3;
		n4 = n3 / 9;
		if (is_even) {
			cout << index << ". " << "even " << n4 << '\n';
		}
		else cout << index << ". " << "odd " << n4 << '\n';
		index++;
	}
}