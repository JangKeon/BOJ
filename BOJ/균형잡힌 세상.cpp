#include <iostream>
#include <queue>
using namespace std;

int main(void) {
	char c;
	queue <char> first;
	queue <char> second;
	string sent;
	while (1) {
		while (c != '\n') {
			cin >> c;
			sent.push_back(c);
			if (c == '(') {
				first.push(c);
			}
		}
		if (sent == ".") {
			break;
		}
	}
}