#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(void) {
	int T;
	cin >> T;
	string str;
	for (int i = 0; i < T; i++) {
		cin >> str;
		queue <char> res;
		int no = 0;
		for (int j = 0; j < str.length(); j++) {
			if (res.empty() && str[j] == ')') {
				no = 1;
				break;
			}
			else if (str[j] == '(') {
				res.push('(');
			}
			else if (str[j] == ')'){
				res.pop();
			}
		}
		if (no || !res.empty()) {
			cout << "NO\n";
		}
		else cout << "YES\n";
	}
}
