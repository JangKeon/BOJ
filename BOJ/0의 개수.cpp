#include <iostream>
#include <string>
using namespace std;

int main(void) {
	int T;
	cin >> T;
	for (int u = 0; u < T; u++) {
		int N, M;
		int result = 0;
		cin >> N >> M;
		for (int i = N; i <= M; i++) {
			string a = to_string(i);
			for (int j = 0; j < a.size(); j++) {
				if (a[j] == '0') {
					result++;
				}
			}
		}
		cout << result << '\n';
	}
}