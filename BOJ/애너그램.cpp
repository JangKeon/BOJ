#include <iostream>
using namespace std;

int main(void) {
	int T;
	cin >> T;
	for (int k = 0; k < T; k++) {
		bool isTrue = false;
		string a, b;
		cin >> a >> b;
		if (a.size() != b.size()) {
			cout << a << " & " << b << " are NOT anagrams.\n";
			continue;
		}
		int first[128];
		int second[128];
		for (int i = 0; i < a.size(); i++) {
			first[a[i]]++;
			second[b[i]]++;
		}

		for (int i = 0; i < 128; i++) {
			if (first[i] != second[i]) {
				isTrue = true;
				break;
			}
		}
		if (!isTrue) {
			cout << a << " & " << b << " are anagrams.\n";
		}
		else cout << a << " & " << b << " are NOT anagrams.\n";

	
	}
}
