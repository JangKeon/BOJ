#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	vector <int> vec;
	int T, N;
	int size = 0;
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	for (int k = 0; k < T; k++) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			char opt;
			int num;
			cin >> opt >> num;
			if (opt == 'I') {
				vec.push_back(num);
				size++;
			}
			else if (opt == 'D' && num == 1) {
				if (size > 0) {
					sort(vec.begin(), vec.end());
					vec.erase(vec.begin() + (size - 1));
					size--;
				}
			}
			else if (opt == 'D' && num == -1) {
				if (size > 0) {
					sort(vec.begin(), vec.end());
					vec.erase(vec.begin());
					size--;
				}
			}
		}
		if (size == 0) {
			cout << "EMPTY\n";
		}
		else {
			cout << vec[size - 1] << ' ' << vec[0];
		}
	}
}