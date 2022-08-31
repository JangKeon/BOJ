#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int main(void) {
	int N, num, res = 0;
	vector <int> v;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	do {
		int sum = 0;
		for (int i = 0; i < N - 1; i++) {
			sum += abs(v[i] - v[i + 1]);
		}
		if (res < sum) res = sum;
	} while (next_permutation(v.begin(), v.end()));
	cout << res << '\n';
}