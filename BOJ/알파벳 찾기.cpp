#include <iostream>
#include <string.h>
using namespace std;

int location[27];

int main(void) {
	string S;
	cin >> S;
	memset(location, -1, sizeof(location));
	for (int i = S.size() - 1; i >= 0; i--) {
		location[S[i] - 'a'] = i;
	}
	for (int i = 0; i < 26; i++) {
		cout << location[i] << " ";
	}
}