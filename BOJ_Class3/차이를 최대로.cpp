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
	sort(vec.begin(), vec.end(), greater<>());
	int result = 0;
	for (int i = 0; i < N - 1; i++) {
		if (N % 2 == 0) {
			for (int i = 0; i < N / 2 - 1; i++) {
				result += abs(vec[i] - vec[N - i - 1]);
			}
			result += abs(vec[0] - vec[N - 1])
		}
		else {

		}
	}
}