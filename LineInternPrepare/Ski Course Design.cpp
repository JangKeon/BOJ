#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	int N, hill;
	cin >> N;
	vector <int> vec;
	for (int i = 0; i < N; i++) {
		cin >> hill;
		vec.push_back(hill);
	}
	int result = 99999999;
	for (int i = 0; i < 83; i++) {
		int sum = 0;
		for (int j = 0; j < vec.size(); j++) {
			if (vec[j] < i) {
				sum += pow(i - vec[j], 2);
			}
			if (i + 17 < vec[j]) {
				sum += pow(vec[j] - (i + 17), 2);
			}
		}
		result = min(result, sum);
	}
	cout << result;
}