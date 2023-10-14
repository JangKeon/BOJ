#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	string s;
	cin >> s;
	transform(s.begin(), s.end(), s.begin(), ::toupper);
	int number[28] = { 0, };
	int max = -1;
	char answer = '0';
	for (int i = 0; i < s.size(); i++) {
		number[s[i] - 'A'] ++;
	}
	for (int i = 0; i < 28; i++) {
		if (max < number[i]) {
			max = number[i];
			answer = char('A' + i);
		}
	}
	int count = 0;
	for (int i = 0; i < 28; i++) {
		if (number[i] == max) {
			count++;
		}
	}
	if (count == 1)	cout << answer;
	else cout << '?';
}