#include <iostream>
#include <string>
using namespace std;

int main(void) {
	string word;
	cin >> word;
	for (int i = 0; i < word.size(); i++) {
		if (word[i] >= 'a' && word[i] <= 'z') {
			word[i] -= 32;
		}
	}
	int arr[150] = {0, };
	for (int i = 0; i < word.size(); i++) {
		arr[word[i]] ++;
	}
	int max = -1;
	for (int i = 62; i < 100; i++) {
		if (max < arr[i]) {
			max = arr[i];
		}
	}
	int a = 0;
	char res;
	for (int i = 62; i < 100; i++) {
		if (arr[i] == max) {
			a++;
			res = i;
		}
	}
	if (a == 1) {
		cout << res << '\n';
	}
	else {
		cout << '?';
	}
}