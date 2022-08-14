#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	string a, res;
	cin >> a;
	bool flag = false;
	vector <char> board;
	int num = 0;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] == 'X') {
			num++;
			if (num == 4) {
				res += "AAAA";
				num = 0;
			}
			if (num == 2 && i == a.size() - 1) {
				res += "BB";
			}
			if (a.size() == 1)	flag = true;
		}
		else {
			if (num == 1 || num == 3) {
				flag = true;
				break;
			}
			else if (num == 2) {
				res += "BB.";
				num = 0;
			}
			else {
				res += ".";
			}
		}
	}
	if (flag)	cout << "-1";
	else cout << res << '\n';

}