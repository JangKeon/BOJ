#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int N, M, num;
	vector <int> nums;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num;
		nums.push_back(num);
	}
	sort(nums.begin(), nums.end());
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> num;
		if (binary_search(nums.begin(), nums.end(), num)) {
			cout << "1\n";
		}
		else cout << "0\n";
	}

}