#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
int main() {
	char s[5] = "";
	while (1) {
		char s[5] = "";
		int count = 0, flag = 0;
		std::cin >> s;
		if (strcmp(s, "0") == 0) {
			exit(0);
		}
		for (int j = 0; j < (strlen(s) / 2) - 1; j++) {
			if (s[j] == s[strlen(s) - 1 - j]) {
				count++;
			}
		}
		if (count == (strlen(s) / 2) - 1) {
			std::cout << "yes\n";
		}
		else {
			std::cout << "no\n";
		}
	}
	return 0;
}