#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	int N, num; 
	cin >> N;
	vector <int> vec;
	for (int i = 0; i < N; i++) {
		cin >> num;
		vec.push_back(num);
	}
	sort(vec.begin(), vec.end());
	for (int i = 0; i < N; i++) {
		cout << vec[i] << '\n';
	}
}