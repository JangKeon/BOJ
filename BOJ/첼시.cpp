#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int main(void) {
	int T, member;
	cin >> T;
	for (int u = 0; u < T; u++) {
		vector <pair <int, string>> vec;
		cin >> member;
		int cost; string name;
		for (int i = 0; i < member; i++) {
			cin >> cost >> name;
			vec.push_back(make_pair(cost, name));
		}
		sort(vec.begin(), vec.end());
		cout << vec[member - 1].second << '\n';
	}
}