#include <iostream>
#include <string>
using namespace std;

bool self_num[20000];

int main() {
	string num;
	for (int i = 1; i <= 10000; i++) {
		int x = 0;
		num = to_string(i);
		for (int j = 0; j < num.size(); j++) {
			x += (num[j] - '0');
		}
		self_num[x + i] = true;
	}
	for (int i = 1; i < 10001; i++) {
		if (!self_num[i]) {
			cout << i << '\n';
		}
	}
}