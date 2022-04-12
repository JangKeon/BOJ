#include <iostream>
using namespace std;

int main(void) {
	int N;
	string result;
	cin >> N;
	for (int i = 0; i < N; i++) {
		string input;
		cin >> input;
		if (i == 0) {
			result = input;
		}
		for (int j = 0; j < input.size(); j++) {
			if (result[j] == input[j]) {
				continue;
			}
			else {
				result[j] = '?';
			}
		}
	}
	cout << result;
}