#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	int T;
	cin >> T;
	for (int u = 0; u < T; u++) {
		vector <int> vec;
		int num;
		for (int i = 0; i < 10; i++) {
			cin >> num;
			vec.push_back(num);
		}
		sort(vec.begin(), vec.end());
		cout << vec[7] << '\n';
	}
}