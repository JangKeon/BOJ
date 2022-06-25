#include <iostream>
#include <string>
using namespace std;

int main(void) {
	string a, b, ans;
	string reverse_a, reverse_b;
	cin >> a >> b;
	for (int i = a.size() - 1; i >= 0; i--) {
		reverse_a.push_back(a[i]);
	}
	for (int i = b.size() - 1; i >= 0; i--) {
		reverse_b.push_back(b[i]);
	}
	int result = stoi(reverse_a) + stoi(reverse_b);
	string res = to_string(result);
	for (int i = res.size() - 1; i >= 0; i--) {
		ans.push_back(res[i]);
	}
	cout << stoi(ans);
}