#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	int T, number;
	cin >> T;
	for (int u = 0; u < T; u++) {
		cin >> number;
		vector <int> convert;
		while (number > 0) {
			if (number % 2 == 0) {
				convert.push_back(0);
				number /= 2;
			}
			else {
				convert.push_back(1);
				number /= 2;
			}
		}
		for (int i = 0; i < convert.size(); i++) {
			if (convert[i]) {
				cout << i << ' ';
			}
		}
		cout << '\n';
	}
}