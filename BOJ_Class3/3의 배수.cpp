#include <iostream>
#include <string>
using namespace std;


int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string X;
	cin >> X;
	int num, cnt = 0;;
	while (X.size() > 1) {
		num = 0;
		for (int i = 0; i < X.size(); i++) {
			num += (X[i] - '0');
		}
		X = to_string(num);
		cnt++;
	}
	cout << cnt << '\n';
	if (stoi(X) % 3 == 0) {
		cout << "YES\n";
	}
	else cout << "NO\n";
}
