#include <iostream>
#include <algorithm>
using namespace std;

int LCS[1001][1001];

int main(void) {
	string a, b;
	int res = 0;
	cin >> a >> b;
	for (int i = 0; i < a.size() + 1; i++) {
		for (int j = 0; j < b.size() + 1; j++) {
			if (i == 0 || j == 0) {
				LCS[i][j] = 0;
			}
			else if (a[i - 1] == b[j - 1]) {
				LCS[i][j] = LCS[i - 1][j - 1] + 1;
			}
			else {
				LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);
			}
		}
	}
	for (int i = 0; i < a.size() + 1; i++) {
		for (int j = 0; j < b.size() + 1; j++) {
			if (res < LCS[i][j]) {
				res = LCS[i][j];
			}
		}
	}
	cout << res;
}