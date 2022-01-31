#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int N, num;
	vector <int> vec;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num;
		vec.push_back(num);
	}
	sort(vec.begin(), vec.end());
	int result = 0;
	for (int i = 0; i < N; i++) {
		result += vec[i] * (N - i);
	}
	cout << result;
}