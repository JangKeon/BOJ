#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	int N, M, num, sum = 0;
	vector <int> vec;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num;
		sum += num;
		vec.push_back(num);
	}
	cin >> M;
	sort(vec.begin(), vec.end());
	if (sum <= M) {
		cout << vec[N - 1] << '\n';
	}
	else {
		 
	}
}