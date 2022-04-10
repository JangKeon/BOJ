#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	int N, K, num, res = 0;
	cin >> N >> K;
	vector <int> vec;
	for (int i = 0; i < N; i++) {
		cin >> num;
		vec.push_back(num);
	}
	
	for (int i = vec.size() - 1; i >= 0; i--) {
		if (K >= vec[i]) {
			while (K >= vec[i]) {
				K -= vec[i];
				res++;
			}
		}
	}
	cout << res;
}