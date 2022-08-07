#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	int T;
	cin >> T;
	for (int u = 0; u < T; u++) {
		vector <int> score;
		int n;
		for (int i = 0; i < 5; i++) {
			cin >> n;
			score.push_back(n);
		}
		sort(score.begin(), score.end());
		if (score[3] - score[1] >= 4) {
			cout << "KIN\n";
		}
		else {
			int sum = 0;
			for (int i = 1; i < 4; i++) {
				sum += score[i];
			}
			cout << sum << '\n';
		}
	}
}