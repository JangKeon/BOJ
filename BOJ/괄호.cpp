#include <iostream>
#include <stack>
using namespace std;
#pragma warning(disable:4996)

int main(void) {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		stack <int> start;
		stack <int> end;
		string a;
		cin >> a;
		for (int j = 0; j < a.size(); j++) {
			if (a[j] == '(') {
				start.push(1);
			}
			else {
				if (!start.empty()) {
					start.pop();
				}
				else end.push(1);
			}
		}
		if (start.empty() && end.empty()) {
			printf("YES\n");
		}
		else printf("NO\n");
	}
	

}