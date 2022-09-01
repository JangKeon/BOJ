#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int main(void) {
	vector <int> vec;
	int num;
	for (int i = 0; i < 4; i++) {
		vec.push_back(i);
	}
	do {
		for (int i = 0; i < vec.size(); i++) {
			cout << vec[i] << ' ';
		}
		cout << '\n';
	} while (next_permutation(vec.begin(), vec.end()));
}