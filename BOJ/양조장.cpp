#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	vector <pair<int, string>> vec;
	int T;
	cin >> T;
	for (int u = 0; u < T; u++) {
		int N;
		cin >> N;
		string school;
		int num;
		for (int i = 0; i < N; i++) {
			cin >> school >> num;
			vec.push_back({ num, school });
		}
		sort(vec.begin(), vec.end(), greater<>());
		cout << vec[0].second << '\n';
	}
}