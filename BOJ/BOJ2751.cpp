#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#pragma warning(disable:4996)

bool compare(int a, int b) {
	return a < b;
}

int main() {
	vector <int> vec;
	int N, num;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num;
		vec.push_back(num);
	}
	sort(vec.begin(), vec.end(), compare);
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << '\n';
	}
}