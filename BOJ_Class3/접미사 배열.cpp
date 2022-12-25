#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector <string> answer;

int main(void) {
	string str;
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		string word;
		for (int j = i; j < str.size(); j++) {
			word.push_back(str[j]);
		}
		answer.push_back(word); 
	}
	sort(answer.begin(), answer.end());
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << '\n';
	}
}
