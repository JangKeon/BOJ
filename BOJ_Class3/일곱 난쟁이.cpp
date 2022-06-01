#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	vector <int> vec;
	int num, sum = 0;
	for (int i = 0; i < 9; i++) {
		cin >> num;
		sum += num;
		vec.push_back(num);
	}
	sort(vec.begin(), vec.end());
	for (int i = 0; i < 8; i++) {
		for (int j = i; j < 9; j++) {
			if (sum - vec[i] - vec[j] == 100) {
				for (int k = 0; k < 9; k++) {
					if (k != i && k != j) {
						cout << vec[k] << ' ';
					}
				}
				return 0;
			}
		}
	}
}