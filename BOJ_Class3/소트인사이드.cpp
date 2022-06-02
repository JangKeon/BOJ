#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(int a, int b) {
	return a > b;
}

int main(void) {
	string N;
	vector <int> vec;
	cin >> N;
	while (!N.empty()) {
		for (int i = 0; i < N.size(); i++) {
			vec.push_back(N.back() - '0');
			N.pop_back();
		}
	}
	sort(vec.begin(), vec.end(), compare);
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i];
	}
}