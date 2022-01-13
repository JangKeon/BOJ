#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool compare(string a, string b) {
	if (a.size() == b.size()) {
		return a < b;
	}
	else {
		return a.size() < b.size();
	}
}
int main() {
	vector <string> vec;
	int N;
	string s;
	cin >> N; 
	for (int i = 0; i < N; i++) {
		cin >> s;
		auto it = find(vec.begin(), vec.end(), s);
		if (it == vec.end()) {
			vec.push_back(s);
		}
		else {
			continue;
		}
	}

	sort(vec.begin(), vec.end(), compare);
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << '\n';
	}

	return 0;
}