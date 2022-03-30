#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int K, N, leng, result = -9999;
vector <int> vec;

long long search(long long low, long long high) {
	int cnt = 0;
	long long mid = (low + high) / 2;
	if (low > high) return result;

	for (int i = 0; i < vec.size(); i++) {
		cnt += vec[i] / mid;
	}

	if (cnt >= N) {
		result = result < mid ? mid : result;
	}

	if (cnt >= N) {
		return search(mid + 1, high);
	}
	else {
		return search(low, mid - 1);
	}
}


int main(void) {
	cin >> K >> N;
	for (int i = 0; i < K; i++) {
		cin >> leng;
		vec.push_back(leng);
	}
	sort(vec.begin(), vec.end());
	search(1, vec[K - 1]);
	cout << result;
}