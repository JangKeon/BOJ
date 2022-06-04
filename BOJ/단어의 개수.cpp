#include <iostream>
using namespace std;

int main(void) {
	char a = ' ';
	string str;
	int result = 0; 
	while (a != '\n') {
		a = cin.get();
		str.push_back(a);
	}
	for (int i = 1; i < str.size(); i++) {
		if (str[i - 1] == ' ' && (str[i] != ' ' && str[i] != '\n')) {
			result++;
		}
	}
	if (str[0] != ' ')	result++;
	cout << result; 
}